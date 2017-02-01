//============================================================================
// Name        : stack.cpp
// Author      : Saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class stack;
class node
{
	friend class stack;
	int data;
	node *pre;
	node (int x)
	{
		data=x;

		pre=NULL;

	}
};
class stack
{
	node *top;
	public: stack()
	{
	top=NULL;
	}
public: void push();
        void pop();
        void display();

};


void stack::push()
{
	int dat;
	cout<<"enter data to be pushed";
	cin>>dat;
	node *p;
	if(top==NULL)
	{
		p=new node(dat);
		top=p;
	}
	else
	{
		p=new node(dat);
		p->pre=top;
		top=p;


	}
}
void stack::pop()
{
	node *p;
	p=top;
if(p==NULL)
{
	cout<<"no stack present";
}
else
{top=p->pre;
	p->pre=NULL;


	delete(p);

}
}

void stack::display()
{
	node *p;
	p=top;
	if(top==NULL)
	{
cout<<"no stack";
	}
	else
	{
		while(p!=NULL){
		cout<<p->data<<"\n";
        p=p->pre;
		}
	}
}
int main() {
	stack s;
	int ch;
	while(1)
	{
		cout<<"\nenter choice 1>push 2>pop 3>display";
		cin>>ch;
		switch(ch)
		{
		case 1:s.push();
		       break;
		case 2:s.pop();
	 	       break;
		case 3:s.display();
			 	       break;
		default: cout<<"wrong choice\n";
		}
	}
	return 0;
}

