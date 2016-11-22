// hdu-1179-二分匹配.cpp : 定义控制台应用程序的入口点。
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
int map[102][102];
int vis[102];
int linker[102];
int n,m;
int dfs(int cur)
{
	for(int i = 1;i<=m;i++)
	{
		if(!vis[i]&&map[cur][i])
		{
			vis[i]=1;
			if(linker[i]==-1||dfs(linker[i]))
			{
				linker[i] = cur;
				return 1;
			}
		}
	}
	return 0;
}
int xiongyali()
{
	int res = 0;
	for(int i = 1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			res++;
	}
	return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i,j,k,sum;  
    while(scanf("%d %d",&n,&m)!=EOF)  
    {  
        sum=0;  
        memset(map,0,sizeof(map));  
        memset(linker,-1,sizeof(linker));  
        for(i=1;i<=m;++i)  
        {  
            scanf("%d",&k);  
            while(k--)  
            {  
                scanf("%d",&j);  
                map[i][j]=1;  
            }  
        }
		sum = xiongyali();
        printf("%d\n",sum);  
    }  
    return 0;
}

