#include<iostream>
#include<string>
#pragma once
using namespace std;
//diem
class Point {
    public:
        double x;
        double y;
        Point();
        ~Point();
        Point(double x,double y);
        void Input();
        void Output();
        bool Compare(Point a);
};
Point::Point()
{
    this->x=0;
    this->y=0;
}
Point::Point(double x,double y)
{
    this->x=x;this->y=y;
}
Point::~Point(){};
void Point::Input()
{
    cout <<"x = ";
    cin >> this->x;
    cout <<"y = ";
    cin >> this->y;
    return;
}
void Point::Output()
{
    cout << "x = "<<this->x<< " y = "<<this->y<< endl;
    return;
}
bool Point::Compare(Point a)
{
    bool k=false;
    if ((this->x==x)&&(this->y==a.y)) k=true;
    return k;
}
//danhsachlienket+quicksort
struct node
{
    Point val;
    node *next;
    node *pre;
    long long n;
};
void AddHead(node* &head,Point x)
{
    node* p;
    p=new node;
    p->val=head->val;
    head->val=x;
    p->next=head->next;
    p->pre=head;
    head->next=p;
    head->n++;
}
void AddTail(node* &head,Point x)
{
    node *p,*a;
    p=new node;
    p->next=NULL;
    p->pre=NULL;
    p->val=x;
    p->n=1;
    if (head==NULL)
        head=p;
    else
    {
        a=head;
        while (a->next != NULL)
            a=a->next;
        p->pre=a;
        a->next=p;
        head->n++; 
    }
}
void AddAfter(node* &head,node* p,Point x)
{
    if(p->next==NULL)   
    {
        AddTail(head,x);
        return;    
    }
    node* q;
    q=new node;
    q->val=x;
    q->next=p->next;
    q->pre=p;
    p->next->pre=q;
    p->next=q;
    head->n++;
}
void DelNode(node* &head,node* p)
{
    if(head->n==0)   return;
    p->pre->next=p->next;
    if(p->next!=NULL)
        p->next->pre=p->pre;
    head->n--;
}