//============================================================================
// Name        : binarytree.cpp
// Author      : saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class binT;
class node
{
	friend class binT;
	public: node *lc,*rc;
	int data;
	node(int d)
	{
		lc=NULL;
		rc=NULL;
		data=d;
	}
};

class binT
{
	node *root;
	public: binT()
	{
		root=NULL;
	}
public: void create();
 	 	void insert(node*);
 	 	void dum();
 	 	void inorder(node*);
 	 	void dum1();
};


void binT::create()
{
	node *p;
	int da;
	cout<<"enter data";
	cin>>da;
	p=new node(da);
	if(root==NULL)
	{
		root=p;
		p->lc=NULL;
		p->rc=NULL;
	}
	else
	{
		cout<<"tree already created";
	}
}

void binT::insert(node* a)
{
	node *n;
	int da1,ch;
	if(root==NULL)
	{
		cout<<"create tree first";

	}
	else
	{

		cout<<"enter 0 for left, 1 for right of "<<a->data;
		cin>>ch;
		if(ch==0)
		{
			if(a->lc==NULL)
			{
				cout<<"enter data";
				cin>>da1;
				n=new node(da1);
				a->lc=n;
			}
			else
			{
				insert(a->lc);
			}
		}
		else
		{
			if(a->rc==NULL)
						{
							cout<<"enter data";
							cin>>da1;
							n=new node(da1);
							a->rc=n;
						}
						else
						{
							insert(a->rc);
						}
		}
	}
}

void binT::dum()
{
	insert(root);
}

void binT::inorder(node* b)
{
	if(b!=NULL){
       	inorder(b->lc);
       	cout<<" "<<b->data<<" ";
       	inorder(b->rc);
       	}
	cout<<"\n";
}

void binT::dum1()
{
	inorder(root);
}

int main() {
	binT b;
	int ch1;
	while(1)
	{
cout<<"enter choice 1>create 2>insert 3>inorder";
cin>>ch1;
switch(ch1)
{
case 1:b.create();
	   break;
case 2:b.dum();
       break;
case 3:b.dum1();
       break;
default: cout<<"wrong choice\n";
}
	}
	return 0;
}
