#include<iostream>
#include"Voronoi.cpp"
using namespace std;
int main()
{
    long long n;//
    node *head=NULL;//
    cout << "n = ";//
    cin >> n;//
    Point x,p1,p2;//
    cout << "Toa do gioi han goc trai: "<<endl;
    p1.Input();
    cout << "Toa do gioi han goc phai: "<<endl;
    p2.Input();
    for (long long i=1;i<=n;i++)
       {
           cout << "Toa do diem p["<<i<<"]:"<<endl;
           x.Input();
           AddTail(head,x);
       }
    Sort(head);
    node *headR=NULL,*headRy=NULL;
    checkPoint(head,headR,headRy,p1,p2);
    system("pause");
    return 0;
}