#include"Point.h"
#include<math.h>
#pragma once
Point CenterOfCircle(Point a,Point b,Point c)
{
    Point i;
    double d=(a.x-b.x)*(c.y-b.y)-(a.y-b.y)*(c.x-b.x),
    dx=(-(b.x*b.x+b.y*b.y-a.x*a.x-a.y*a.y)/2)*(c.y-b.y),
    dy=(a.x-b.x)*((c.x*c.x+c.y*c.y-b.x*b.x-b.y*b.y)/2);
    dx=dx-((c.x*c.x+c.y*c.y-b.x*b.x-b.y*b.y)/2)*(a.y-b.y);
    dy=dy-(c.x-b.x)*(-(b.x*b.x+b.y*b.y-a.x*a.x-a.y*a.y)/2);
    i.x=dx/d;
    i.y=dy/d;
    return i;
}
long double RadiusOfCircle(Point i,Point a)
{
    long double r;
    r=sqrt(pow(a.x-i.x,2)+pow(a.y-i.y,2));
    return r;
}