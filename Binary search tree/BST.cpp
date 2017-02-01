//============================================================================
// Name        : BST.cpp
// Author      : Saurabh 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class tree;

class node
{
	friend class tree;
	public: node *lc,*rc;
	        int data;
	 node(int x)
		{
		lc=NULL;
		rc=NULL;
		data=x;
		}
};
class tree
{
 node *root;
public: tree()
      {
	  root=NULL;
      }
public: void create();
        void ins();
        void inorder(node*);
        void dummy();
        void preorder(node*);
        void dummy1();
        void postorder(node*);
        void dummy2();
        void desc(node*);
        void dummy3();
        void search(int);
        void delete12(node* , node*);


};
void tree::dummy()
{
	inorder(root);
}
void tree::dummy1()
{
	preorder(root);
}
void tree::dummy2()
{
	postorder(root);
}
void tree::dummy3()
{
	desc(root);
}

void tree::inorder(node* a)
       {
       	if(a!=NULL){
       	inorder(a->lc);
       	cout<<" "<<a->data<<" ";
       	inorder(a->rc);
       	}
       }

void tree::postorder(node* a)
       {
       	if(a!=NULL){
       	postorder(a->lc);

       	postorder(a->rc);
       	cout<<" "<<a->data<<" ";
       	}
       }

void tree::desc(node* a)
       {
       	if(a!=NULL){

       	desc(a->rc);
       	cout<<" "<<a->data<<" ";
       	desc(a->lc);
       	}
       }

void tree::preorder(node* a)
       {
       	if(a!=NULL){

       	cout<<" "<<a->data<<" ";
       	preorder(a->lc);
    	preorder(a->rc);
       	}
       }

void tree::create()
{
node *p;
int dat;
cout<<"Enter root";
cin>>dat;
p=new node(dat);
if(root==NULL)
{
	root=p;
	p->lc=NULL;
	p->rc=NULL;

}
else
{
	cout<<"tree is created";
}
}

void tree::ins()
{
	node *p,*q;
if(root==NULL)
{
	cout<<"create tree first";
}
else
{int da;
	cout<<"Enter data";
	cin>>da;
	p=root;
	q=root;
	while(q!=NULL)
	{
		p=q;
	if(da<p->data)
	{
		q=p->lc;
	}
	else
	{
		q=p->rc;
	}
	}
	if(da<p->data)
	{
		q=new node(da);
		p->lc=q;
	}
	else
	{
		q=new node(da);
				p->rc=q;
	}
}
}


void tree::search(int x)
{
node *t,*s;
s=t=root;
while(t!=NULL)
{
	
	if(x<t->data)
	{
		t=t->lc;
		s=t;
	}
	else if(x>t->data)
	{
		t=t->rc;
		s=t;
	}
	else
	{
		delete12(t,s);
	}
}
}

void tree::delete12(node* u, node* t)
		{
	if(t->rc==NULL && t->lc==NULL)
	{
	t->rc=NULL;
	t->lc=NULL;
	}
	else if(t->lc==NULL)
	{
if(u->data<t->data)
{
	t->lc=u->rc;
	u->rc=NULL;
}
else
{
	t->rc=u->rc;
		u->rc=NULL;
}
	}
	else if(t->rc==NULL)
	{
		if(u->data<t->data)
		{
			t->rc=u->lc;
			t->lc=NULL;
		}
		else
		{
			
		}
			
			
	}
		}


int main() {
	tree s;
		int ch;
		while(1)
		{
			cout<<"\nenter choice 1>create 2>insert 3>inorder 4>preorder 5>postorder 6>desc";
cin>>ch;
			switch(ch)
			{
			case 1:s.create();
			       break;
			case 2:s.ins();
		 	       break;
			case 3:s.dummy();
			       break;
			case 4:s.dummy1();
						       break;
			case 5:s.dummy2();
									       break;
			case 6:s.dummy3();
									       break;


			default: cout<<"wrong choice\n";
			}
		}
	return 0;
}
