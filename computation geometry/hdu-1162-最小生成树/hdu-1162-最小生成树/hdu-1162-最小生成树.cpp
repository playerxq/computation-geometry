// hdu-1162-最小生成树.cpp : 定义控制台应用程序的入口点。
// hdu-1101-prim.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 110
struct Node//定义点 
{
    double x,y;
}node[MAX];
const int maxx = 0x3f3f3f3f;
double distance(Node a,Node b)//两点的距离 
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double map[MAX][MAX];
int used[MAX];
double f[MAX];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,j,k;
	double minx;
	double sum;
	while(scanf("%d",&n)!=EOF)
	{
		memset(used,0,sizeof(used));
		for(int i = 0;i<n;i++)
		{
			scanf("%lf%lf",&node[i].x,&node[i].y);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					map[i][j] = 0;
				else
					map[i][j] = distance(node[i],node[j]);
			}
		}
		used[0]= 1;
		for(i=1;i<n;i++)
		{
			f[i]=map[0][i];
		}
		sum=0;
		for(i=1;i<n;i++)
		{
			minx=maxx;
			for(j=0;j<n;j++)
			{
				if(!used[j]&&f[j]<minx)
				{
					minx=f[j];k=j;
				}
			}
			used[k]=1;sum+=f[k];
			for(j=0;j<n;j++)
			{
				if(!used[j]&&f[j]>map[k][j])
				{
					f[j]=map[k][j];
				}
			}
		}
		printf("%.2lf\n",sum);
	}
}



