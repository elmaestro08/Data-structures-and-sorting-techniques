//============================================================================
// Name        : Doubly_cirLL.cpp
// Author      : saurabh
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class cll;
class node
{
int data;
node *next,*pre;
friend class cll;
node(int x)
{
data=x;
next=NULL;
pre=NULL;
}
};
class cll
{
node *start;
public:
void display();
void insert();
void insert_at();
void delete_s();
void delete_at();
void insert_bef();
void delete_bef();
cll()
{
start=NULL;
}
};
void cll::insert(){
node *p;
int no;
cout<<"enter no";
cin>>no;
p=new node(no);
if(start==NULL)
{
p->next=p;
p->pre=p;
start=p;
}
else
{
p->next=start;
p->pre=start->pre;
start->pre->next=p;
start->pre=p;
start=p;
}
}



void cll::display(){
node *temp,*p;
temp=start;
if(start==NULL){
cout<<"EMPTY lIST\n";
}
else{
while(temp!=NULL)
{
p=temp->next;
cout<<temp->data<<"\t";
if(p==start)
{
break;
}
temp=temp->next;
}
cout<<"\n";
}
}
void cll::delete_s()
{
node *p;
if(start==NULL){
cout<<"EMPTY lIST\n";
}
else {
p=start;
start=p->next;
start->pre=p->pre;
p->pre->next=start;
delete(p);
}
}
void cll::insert_at()
{
int a,b,f=0; node *p,*temp;
if(start==NULL){
cout<<"EMPTY lIST\n";
}
else {
cout<<"the data after which and data";
cin>>a>>b;
p=start;
while(p!=NULL)
{
if(p->data==a)
{
f=1; break;
}
else
{
p=p->next;
}
}
if(f==1)
{
temp=new node(b);
temp->next=p->next;
p->next->pre=temp;
p->next=temp;
temp->pre=p;
}
else
{
cout<<"no not found\n";
}
}
}
void cll::delete_at()
{
node *p,*temp;
p=start; int c;
if(start==NULL){
cout<<"EMPTY lIST\n";
}
else{
cout<<"wat?";
cin>>c;
while(p->next!=start)
{
temp=p->next;
if(temp->data==c)
{
p->next=temp->next;
temp->next->pre=p;
delete(temp);
}
else
{
p=p->next;
}
}
}
}
void cll::insert_bef()
{
node *p,*temp;
temp=start;
int n,n1,f=0;
if(start==NULL){
cout<<"EMPTY lIST\n";
}
else{
cout<<"before what and wat";
cin>>n>>n1;
p=new node(n1);
while(temp!=NULL)
{
if(temp->data==n)
{
f=1; break;
}
else
{
temp=temp->next;
}

}
if(f==0)
{
cout<<"no not found\n";
}
else
{
p->next=temp;
p->pre=temp->pre;
temp->pre->next=p;
temp->pre=p;
}
}
}
void cll::delete_bef()
{
int n;
if(start==NULL){
cout<<"EMPTY lIST\n";
}
else
{
cout<<"before wat";
cin>>n;
node *p,*q;
p=start;
while(p!=NULL)
{

q=p->pre;
if(p->data==n)
{
if(q->pre==NULL)
{
p->pre=q->pre;
p=start;
delete(q);
break;
}
else
{
p->pre=q->pre;
q->next=NULL;
q->pre->next=p;
delete(q);
break;
}
}
else
{
p=p->next;
}
}
}
}
int main(){
cll s1;
int ch;
while(1)
{
cout<<"enter choice 1>insert\n 2>display\n 3>insert aft\n 4>insert before\n 5>delete start\n 6>delete at\n 7>delete before\n ";
cin>>ch;
switch(ch)
{
case 1:s1.insert();
break;
case 2:s1.display();
break;
case 3:s1.insert_at();
break;
case 4:  s1.insert_bef();
break;
case 5: s1.delete_s();
break;
case 6: s1.delete_at();
break;
case 7:  s1.delete_bef();
break;
default:cout<<"wrong choice\n";
}
}
return 0;
}
