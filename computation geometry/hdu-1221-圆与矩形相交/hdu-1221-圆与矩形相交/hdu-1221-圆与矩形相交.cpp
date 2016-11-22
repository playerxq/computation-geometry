// hdu-1221-圆与矩形相交.cpp : 定义控制台应用程序的入口点。
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
const int INF = 0x3fffffff;
double x,y,r;
double rx[5];
double ry[5];
double diss(double x, double y, double a, double b)
{
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		double a,b,c,d;
		memset(rx,0,sizeof(rx));
		memset(ry,0,sizeof(ry));
		scanf("%lf%lf%lf%lf%lf%lf%lf",&x,&y,&r,&a,&b,&c,&d);
		if((a<c&&b<d)||(c<a&&d<b))
		{
			if(a<c&&b<d)
			{
				rx[4] = a;
				ry[4] = b;
				rx[2] = c;
				ry[2] = d;
				rx[1] = rx[4];
				ry[1] = ry[2];
				rx[3] = rx[2];
				ry[3] = ry[4];
			}
			else
			{
				rx[4] = c;
				ry[4] = d;
				rx[2] = a;
				ry[2] = b;
				rx[1] = rx[4];
				ry[1] = ry[2];
				rx[3] = rx[2];
				ry[3] = ry[4];
			}
		}
		else
		{
			if(a<c)
			{
				rx[1] = a;
				ry[1] = b;
				rx[3] = c;
				ry[3] = d;
				rx[2] = rx[3];
				ry[2] = ry[1];
				rx[4] = rx[1];
				ry[4] = ry[3];
			}
			else
			{
				rx[1] = c;
				ry[1] = d;
				rx[3] = a;
				ry[3] = b;
				rx[2] = rx[3];
				ry[2] = ry[1];
				rx[4] = rx[1];
				ry[4] = ry[3];
			}
		}
		double minx = INF;
		double maxx = -1;
		for(int i = 1;i<5;i++)
		{
			if(diss(x,y,rx[i],ry[i])<minx)
				minx = diss(x,y,rx[i],ry[i]);
			if(diss(x,y,rx[i],ry[i])>maxx)
				maxx = diss(x,y,rx[i],ry[i]);
		}
		if(maxx<r)
		{
			printf("NO\n");
			continue;
		}
		if(x>=rx[1]&&x<=rx[3])
		{
			if((fabs(y-ry[1])<=r||fabs(y-ry[3])<=r)||(fabs(y-ry[2])<=r||fabs(y-ry[4])<=r))
			{
				printf("YES\n");
				continue;
			}
		}
		if(y>=ry[3]&&y<=ry[1])
		{
			if(fabs(x-rx[1])<=r||fabs(x-rx[3])<=r)
			{
				printf("YES\n");
				continue;
			}
		}
		if(minx<=r)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
}

