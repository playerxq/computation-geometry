// hdu-1154-多边形.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct Point  
{  
    double x;  
    double y;  
} p[1001], px[10001];  
int n;  
double eps=1e-8;
int cmp(Point a, Point b)  
{  
    if(abs(a.x-b.x)<eps)  
        return a.y<b.y;  
    return a.x<b.x;  
}
double dist(Point a,Point b)//求距离  
{  
    return sqrt((a.x - b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));  
}
double direction(Point a, Point b, Point c)
{
	return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}
bool on_segment(Point pi,Point pj,Point pk)//判断点pk时候在线段pi, pj上  
{  
    if(direction(pi, pj, pk)==0)  
    {  
        if(pk.x>=min(pi.x,pj.x)&&pk.x<=max(pi.x,pj.x)&&pk.y>=min(pi.y,pj.y)&&pk.y<=max(pi.y,pj.y))  
            return true;  
    }  
    return false;  
}
bool segments_intersect(Point p1,Point p2,Point p3,Point p4)//判断线段是否相交  
{  
    double d1=direction(p3,p4,p1);  
    double d2=direction(p3,p4,p2);  
    double d3=direction(p1,p2,p3);  
    double d4=direction(p1,p2,p4);  
    if(d1*d2<0&&d3*d4<0)  
        return true;  
    else if(d1==0&&on_segment(p3,p4,p1))  
        return true;  
    else if(d2==0&&on_segment(p3,p4,p2))  
        return true;  
    else if(d3==0&&on_segment(p1,p2,p3))  
        return true;  
    else if(d4==0&&on_segment(p1,p2,p4))  
        return true;  
    return false;  
}
Point intersection(Point a1, Point a2, Point b1, Point b2)//计算线段交点  
{  
    Point ret = a1;  
	double t = ((a1.x-b1.x)*(b1.y-b2.y)-(a1.y-b1.y)*(b1.x-b2.x))/((a1.x-a2.x)*(b1.y-b2.y)-(a1.y-a2.y)*(b1.x-b2.x));
	ret.x += (a2.x-a1.x)*t;
	ret.y += (a2.y-a1.y)*t;
	return ret;  
}
int InPolygon(Point a)//判断点是否在多边形的内部  
{  
    int i;  
    Point b,c,d;  
    b.y=a.y;  
    b.x=1e15;//定义射线  
    int flag=0;  
    int count=0;  
    for(i=0; i<n; i++)  //对多边形每个边
    {  
        c = p[i];  
        d = p[i + 1];  
        if(on_segment(c,d,a))//该点在多边形的一条边上  
            return 1;  
        if(abs(c.y-d.y)<eps)  
            continue;  
        if(on_segment(a,b,c))//和顶点相交的情况，如果y值较大则取  
        {  
            if(c.y>d.y)  
                count++;  
        }  
        else if(on_segment(a,b,d))//和顶点相交的情况，如果y值较大则取  
        {  
            if(d.y>c.y)  
                count++;  
        }  
        else if(segments_intersect(a,b,c,d))//和边相交  
            count++;  
    }  
    return count%2;//当L和多边形的交点数目C是奇数的时候，P在多边形内，是偶数的话P在多边形外。  
} 
bool Intersect(Point s,Point e,Point a,Point b)  
{  
    return direction(e,a,s)*direction(e,b,s)<=0;  
}//所在直线相交 
double caculate(Point s,Point e)
{
	int i,j,k=0;  
    double sum;  
    Point a,b,temp;
	for(i = 0;i<n;i++)
	{
		a = p[i];
		b = p[i+1];
		if(abs(direction(e,a,s))<eps&&abs(direction(e,b,s))<eps)
		{
			px[k++] = a;
			px[k++] = b;
		}
		else if(Intersect(s,e,a,b))
		{
			px[k++]=intersection(s,e,a,b);
		}
	}
	if(k==0)  
        return 0.0; 
	sort(px,px+k,cmp);
	px[k]=px[0];
	sum=0;
	for(i=0; i<k-1; i++)  
    {  
        a=px[i];  
        b=px[i+1];  
        temp.x=(a.x+b.x)/2.0;  
        temp.y=(a.y+b.y)/2.0;  
        if(InPolygon(temp))//如果两点的中点在多边形外部，说明直线在外部  
            sum+=dist(a,b);  
    }  
    return sum; 
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int q,i,j;
	double sum;
	Point s,e;
	while(~scanf("%d%d",&n,&q))  
    {  
        if(q==0&&n==0)  
            break;  
        for(i=0; i<n; i++)  
            scanf("%lf%lf",&p[i].x,&p[i].y);  
        p[n]=p[0];  
        for(j=0; j<q; j++)  
        {  
            scanf("%lf%lf%lf%lf",&s.x,&s.y,&e.x,&e.y);  
            sum=caculate(s,e);  
            printf("%.3f\n",sum);  
        }  
    }
}

