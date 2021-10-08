#include"Point.h"
#include"Circle.h"
#include<vector>
#pragma  once
using namespace std;
node* NODE(long long n, node* head)
{
    node *a=head;
    for (int i=1; i<=n; i++)
        a=a->next;
    return a;
}

void quick_sort(node* head, long long left, long long right)
{
    long long i=left, j= right;
    if (i>=j) return;
    while (i<j)
    {
        while ( NODE(i,head)->val.y > NODE(right,head)->val.y ) i++;
        while ( NODE(j,head)->val.y <= NODE(right,head)->val.y && i<j ) j--;
        swap(NODE(i,head)->val,NODE(j,head)->val);
    }
    swap(NODE(i,head)->val,NODE(right,head)->val);
    quick_sort(head, left, i-1);
    quick_sort(head, i+1 , right); 
}
void Sort(node* head)
{
    node*p=head;
    int i=0;
    while (p->next != NULL)
    {
        p=p->next;
        i++;
    }
    quick_sort(head,0,i);
}
void Print(node* head)
{
    node* p=head;
    while (p!=NULL)
    {
        cout << "x = "<<p->val.x<<" y = "<<p->val.y<<endl;
        p=p->next;
    }
}
//xuliparabol
node* Parabool(node* headRy,Point check,Point limit)
{
    node* p;
    p=headRy;
    double min=limit.y;
    node* M=NULL;
    while(p!=NULL)
    {
        double y=(1/(2*(p->val.y-check.y)))*(pow(check.x,2)-2*p->val.x*check.x+pow(p->val.x,2)+pow(p->val.y,2)-pow(check.y,2));
        if (y<min) {
            min=y;
            M=p;
        }
        p=p->next;
    }
    return M;
}
void checkPara(node* &headR,Point limitleft,Point limitright,double y)
{
    node* p=NULL;
    p=headR;
    double y1=(1/(2*(p->val.y-y)))*(pow(limitleft.x,2)-2*p->val.x*limitleft.x+pow(p->val.x,2)+pow(p->val.y,2)-pow(y,2));
    double y2=(1/(2*(p->next->val.y-y)))*(pow(limitleft.x,2)-2*p->next->val.x*limitleft.x+pow(p->next->val.x,2)+pow(p->next->val.y,2)-pow(y,2));
    if(y2<=y1&&y2<=limitleft.y)  
    {
        p=p->next;
        p->pre=NULL;
        p->n=headR->n-1;
        headR=p; 
    }
    while(p->next!=NULL)
        p=p->next;
    y1=(1/(2*(p->val.y-y)))*(pow(limitright.x,2)-2*p->val.x*limitright.x+pow(p->val.x,2)+pow(p->val.y,2)-pow(y,2));
    y2=(1/(2*(p->pre->val.y-y)))*(pow(limitright.x,2)-2*p->pre->val.x*limitright.x+pow(p->pre->val.x,2)+pow(p->pre->val.y,2)-pow(y,2));
    if(y2<=y1&&y2<=limitleft.y)      
        DelNode(headR,p);
}
//xetdinh
bool TopVoronoi(Point a,Point b,Point c,node* &head)
{
    Point i=CenterOfCircle(a,b,c);
    long double r=RadiusOfCircle(i,b);
    long double y2=i.y-r;
    node* p=head;
    bool check=true;
    while ((p->next!=NULL)&&(y2<=p->val.y))
    {
        if(r>RadiusOfCircle(i,p->val))  {
            check=false;
            break;
        } 
        p=p->next;
    }
    return check;
}
void checkPoint(node* &head,node* &headR,node* &headRy,Point limitleft,Point limitright)
{
    node* p=head;
    while (p!=NULL)
    {
        if(headR==NULL){
            AddTail(headR,p->val);
            AddTail(headRy,p->val);
        }
        else
        {
            if (headR->n>2) checkPara(headR,limitleft,limitright,p->val.y);
            node* pRy=NULL;
            pRy=Parabool(headRy,p->val,limitleft);
            if(pRy!=NULL)
                {
                    node* pR=headR;
                    while (pR->val.Compare(pRy->val)!=true)
                        pR=pR->next;
                    AddAfter(headR,pR,pR->val);
                    AddAfter(headR,pR,p->val);
                    AddHead(headRy,p->val);
                }
            if(pRy==NULL)
            {
                node* pR=headR;
                while ((p->val.x>pR->val.x)&&(pR->next!=NULL))
                {
                    if(pR->next->val.x>p->val.x) break;
                    pR=pR->next;
                }
                AddAfter(headR,pR,p->val);
                AddHead(headRy,p->val);
            }
        }
        if (headR->n>2)
        {
            node *q=headR->next;
            while (q->next!=NULL)
            {
                if ((q->val.Compare(q->pre->val)==false)&&(q->val.Compare(q->next->val)==false)&&(q->pre->val.Compare(q->next->val)==false))
                    if(TopVoronoi(q->pre->val,q->val,q->next->val,head)==true)
                    {
                        Point I=CenterOfCircle(q->val,q->next->val,q->pre->val);
                        cout << "Toa do diem: "<<endl;
                        q->val.Output();
                        q->pre->val.Output();
                        q->next->val.Output();
                        cout<< "toa do dinh: "<<endl;
                        I.Output();
                        cout << endl;
                        q=q->next;
                        DelNode(headR,q->pre);
                        if(q->next!=NULL)   q=q->next;
                    }
                    else q=q->next;
                else    q=q->next;
            }
        }
        p=p->next;
    }
}


