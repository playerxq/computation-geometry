// hdu-1068-最大匹配.cpp : 定义控制台应用程序的入口点。
//最大独立集 =顶点数 - 最大匹配数
//匈牙利算法求最大匹配
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
const int MAXN=1000;
int map[MAXN][MAXN];
int n;
int linker[MAXN];
int vis[MAXN];
int dfs(int a)
{
	for(int i = 0;i<n;i++)
	{
		if(!vis[i]&&map[a][i]!=0)
		{
			vis[i]=1;
			if(linker[i]==-1||dfs(linker[i]))
			{
				linker[i]=a;
				return 1;
			}
		}
	}
	return 0;
}
int xiongyali()
{
	int num=0;
	memset(linker,-1,sizeof(linker));
	for(int i = 0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			num++;
	}
	return num;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	 int i,j,num,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        for(i=1;i<=n;i++)
        {
                scanf("%d: (%d)",&a,&num);
                for(j=0;j<num;j++)
                {
                    scanf("%d",&b);
                    map[a][b]=1;
                }    
        } 
        int cnt=xiongyali();
        printf("%d\n",n-cnt/2);
        
    }  
    return 0;
}

