//============================================================================
// Name        : hashing.cpp
// Author      : saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class hash1
{

int hash[10];
int chain[10];
int flag[10];
string name[10];
public: hash1()
{

	for(int i=0;i<10;i++)
	{
		name[i]="null";
		hash[i]=0;
		chain[i]=-1;
		flag[i]=0;
	}
}

public: int hfn(int);
		void ins_ch(int,string);
		void ch(int,int,string);
		void disp();
		int back(int);
			void ins_ch1(int,string );
		void lp(int,string);
		void lp1(int,int,string);
		void displp();
		void ch1(int,int,string);
};

int hash1::back(int a)
{
	if(a==0)
	{
		return 9;
	}
	else
	{
		return (a-1);
	}
}
int hash1::hfn(int n)
{
	int y;
	y=n%10;
	return y;
}

void hash1::ins_ch(int no,string f)
{
	int s=hfn(no);
	if(hash[s]==0)
	{
		hash[s]=no;
		name[s]=f;
		flag[s]=1;
	}
	else
	{


		ch(s,no,f);

		}
}
void hash1::ch(int s,int i,string j)
{
	int y;

int z=(s+1)%10;
if(hash[z]==0)
{
	hash[z]=i;
	name[z]=j;
	y=back(z);
	while(flag[y]==1)
	{
		if((hash[y]%10)==(i%10))
		{
			chain[y]=z;
			flag[z]=1;
			break;
		}
		else
		{
			y=back(y);
		}
	}

}
else
{
	ch(z,i,j);
}
}

void hash1::disp()
{
	for(int i=0;i<10;i++)
	{
		cout<<i<<"\t"<<hash[i]<<"\t"<<name[i]<<"\t"<<chain[i];
		cout<<"\n";
	}
}





void hash1::ins_ch1(int no,string c)
{
	int s=hfn(no);
	int a1,l;
	if(hash[s]==0)
	{
		hash[s]=no;
		name[s]=c;
		flag[s]=1;
	}
	else if(s!=(hash[s]%10))
	{
 a1=hash[s];
hash[s]=no;
name[s]=c;
int l=chain[s];
chain[s]=-1;
for(int i=0;i<10;i++)
{
	int a;
	if(chain[i]==s)
	{
		chain[i]=l;
		ch1(s,a1,c);
		break;
	}
}

	}
	else
	{
		ch1(s,no,c);
	}


	}



void hash1::lp(int e,string j)
{
	int s=hfn(e);
		if(hash[s]==0)
		{
			hash[s]=e;
			name[s]=j;
			flag[s]=1;
		}
		else
		{


			lp1(s,e,j);

			}
}

void hash1::lp1(int j,int k,string w)
{

	int z=(j+1)%10;
	if(hash[z]==0)
	{
		hash[z]=k;
		name[z]=w;
			flag[z]=1;
		}
	else
	{
		lp1(z,k,w);
	}

}
void hash1::displp()
{
	for(int i=0;i<10;i++)
		{
			cout<<i<<"\t"<<hash[i]<<"\t"<<name[i];
			cout<<"\n";
		}
}


void hash1::ch1(int s,int i,string o)
{
	int y;
int z=(s+1)%10;
if(hash[z]==0)
{
	hash[z]=i;
	name[z]=o;
	flag[z]=1;
	y=back(z);
	while(flag[y]==1)
	{
		if((hash[y]%10)==(i%10))
		{
			chain[y]=z;

			break;
		}
		else
		{
			y=back(y);
		}
	}

}
else
{
	ch1(z,i,o);
}
}

int main() {
int ch,no;
string name;
hash1 h;
	while(1)
{
	cout<<"\nenter choice \n1.insert chaining without rep \n2.insert chaining with rep \n3>linear probing \n4.display chaining \n5>display lp";
	cin>>ch;
	switch(ch)
	{
	case 1:cout<<"enter emp number and name";
	cin>>no>>name;
		h.ins_ch(no,name);

		break;
	case 2: cout<<"enter emp number nd name ";
	cin>>no>>name;
		h.ins_ch1(no,name);
			break;
	case 3: cout<<"enter emp number nd name";
	cin>>no>>name;
			h.lp(no,name);
				break;
	case 4:h.disp();
		break;
	case 5:h.displp();
			break;
	default: cout<<"wrong choice";
	}
}
	return 0;
}
