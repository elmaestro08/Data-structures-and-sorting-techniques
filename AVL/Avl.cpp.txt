//
============================================================================
// Name        : avl.cpp
// Author      : Saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
#include<string.h>
#include<fstream>

using namespace std;
class avltree;   //forward declaration
class node
{
public:
    string keyw;
    string meaning;
    int bf;
    node *lchild, *rchild;
    friend class tree;
  node(string y,string z)
  {
      keyw = y;
      meaning = z;
      bf = 0;
      lchild = rchild=NULL;
  }
};
class avltree
{
    node *root;
    public:
    void display();
    void inorder(node *);
    int insert(string,string);   //char *, char *);
    avltree()
    {
        root = NULL;
    }
 };
void avltree :: display()
{
    inorder(root);
}
void avltree :: inorder(node *t)
{
    if (t!= NULL)
    {
        inorder(t->lchild);
        cout<<t->keyw<<" balance factor is "<<t->bf<<"\n";
        inorder(t->rchild);
    }

}
 int avltree :: insert (string y1,string z)     //char *y1,char *z)
{
      node  *a , *b , *c, *f, *p, *q, *y ;
      int found , unbalanced, d ;
      unbalanced = 1 ;
      if (!root)
      {
       y = new node(y1,z);
       root =  y;
       return(0);
      }

      f = q = NULL ;
      found = 0 ;
      a = p = root ;
      while(p && !found )
      {
      if (p->bf)
      {
      a = p ;
      f = q ;
      }
      if (y1 < p->keyw)   ///(x < p-> data)
      {
          q = p ;
          p = p-> lchild ;
      }
      else if (y1> p->keyw)    //(x > p->data)
      {
          q = p ;
          p= p->rchild;
      }
      else
      {
          y = p ;
          found = 1 ;

      }
      }
      //  end while
      if (found!=1)
      {
      y = new node(y1,z) ;
      if(y1< q->keyw)
          q->lchild = y ;
      else
          q->rchild = y ;

      if (y1>a->keyw)
      {
      p = a-> rchild ;
      b = p ;
      d = -1 ;
      }
      else
      {
      p = a->lchild ;
      b = p ;
      d = 1 ;
      }
      while(p!= y)
      {
      if (y1<p->keyw)
      {
       p->bf = 1  ;
       p = p-> lchild ;
      }
      else
      {
          p->bf =-1  ;
          p = p->rchild ;
      }
      }
      if(!(a->bf)||!(a->bf+d))
      {
          a->bf += d ;
          unbalanced  = 0;
      }
      if(unbalanced)
      {
      if(d==1)
      {
      if(b->bf==1)
      {
          a->lchild = b->rchild ;
          b->rchild = a ;
          a->bf = b->bf = 0;
      }
      else
      {
      c = b -> rchild ;
      b-> rchild = c->lchild ;
      a->lchild  = c->rchild ;

      c -> lchild = b ;
      c-> rchild = a;
      switch(c-> bf)
      {
      case 1 :
          a->bf = -1;
           b-> bf = 0 ;
           break ;
      case -1 :
          b->bf = 1 ; a ->bf  = 0 ;
            break ;
      case 0 : a->bf = b->bf = 0 ;
            break;
      }
      c->bf  = 0 ;
      b = c ;
      }
      // end else
      }
      //end if (d == 1)
      else
      {
      if(b->bf==-1)
      {
      a->rchild = b->lchild ;
      b-> lchild = a ;
      a->bf = b-> bf = 0 ;
      }
      else
      {
      c = b->lchild ;
      b->lchild  = c->rchild ;
      a->rchild = c->lchild ;
      c->rchild = b ;
      c->lchild = a ;
      switch (c->bf )
      {
      case 1: a->bf =0 ;
                  b->bf = -1 ;
                  break ;
      case -1  : a->bf = +1;
                 b->bf = 0 ;
                    break ;
      case 0 :  a->bf=b->bf = 0;
                    break ;
      }
      c->bf = 0;
      b= c ;
      }
      // end else
      }
      //end  // else (d = = 1 )
      if (!f)
        root = b ;
      else if(a ==f->lchild)
          f->lchild = b;
      else if(a== f->rchild)
          f-> rchild = b ;
      } //end unbalance .

      }       // end  if (! found )
      return 1 ;
}
int main()
{
    fstream f1;
    ifstream f2;
    avltree a1;
    //input i1;
    int ch,opt,n;
    string k,m;
    do
    {

    cout<<" program for AVL tree";
    cout<<"1. Create/Insert  \n  2.Display 3. Create file/add record in file \n 4. Display file content";
    cout<<" Enter your choice";
    cin>>ch;
    switch (ch)
    {
    case 1:
             cout<<" Enter keyword to be entered";
             cin.ignore();
             cin>>k;
             cout<<" Enter meaning to be entered";
             cin.ignore();
             cin>>m;
             a1.insert(k,m);
             break;
    case 2 : a1.display();
            break;
/*    case 3 :

           cout<<"How many record u want to add in file";
           cin>>n;
           for(int i=0;i<n;i++)
           {
               i1.getdata();
               f1.open("try.txt",ios::binary|ios::app);
               f1.write((char*)&i1,sizeof(i1));
               f1.close();
           }
    //       f1.close();
           break;
    case 4 :
            f2.open("try.txt",ios::binary|ios::in);
            cout<<"Record in a file are";
            f2.seekg(ios::beg);
            while(f2.read((char*)&i1,sizeof(i1)))
                    i1.display();
            f1.close();
            break;*/
    }
    cout<<" do you want to continue press 1 for continue";
    cin>>opt;
    }while(opt ==1);
    return 0;
}