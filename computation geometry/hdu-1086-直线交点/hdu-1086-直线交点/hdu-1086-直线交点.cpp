// hdu-1086-直线交点.cpp : 定义控制台应用程序的入口点。
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
struct point
{
	double x, y;
};
double cross(point p1, point p2, point p)
{
	return (p1.x-p.x)*(p2.y-p.y)-(p2.x-p.x)*(p1.y-p.y);
}
int inseg( point p1,point p2 ,point p )
{
    double max=p1.x > p2.x ? p1.x : p2.x ;
    double min =p1.x < p2.x ? p1.x : p2.x ;
 
    if( p.x >=min && p.x <=max )
        return 1;
    else
        return 0;
}
int judge(point p1, point p2, point p3, point p4)
{
	double d1,d2,d3,d4;
	d1 = cross(p1,p2,p3);
	d2 = cross(p1,p2,p4);
	d3 = cross(p3,p4,p1);
	d4 = cross(p3,p4,p2);
	if(d1*d2<0&&d3*d4<0)
		return 1;
	if(d1==0&&inseg(p1,p2,p3))
		return 1;
	if(d2==0&&inseg(p1,p2,p4))
		return 1;
	if(d3==0&&inseg(p3,p4,p1))
		return 1;
	if(d4==0&&inseg(p3,p4,p2))
		return 1;
	return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,j,num;
    point begin[105],end[105];
 
    while( scanf("%d",&n) && n!=0 )
    {
        num=0;
        for( i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf",&begin[i].x ,&begin[i].y ,&end[i].x ,&end[i].y );
        }
        for( i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                {
                    if( judge( begin[i],end[i],begin[j],end[j] ) )
                        num++;
                }
        printf("%d\n",num);
    }
    return 0;
}

