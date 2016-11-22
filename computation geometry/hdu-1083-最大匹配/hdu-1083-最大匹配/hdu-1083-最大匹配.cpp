// hdu-1083-最大匹配.cpp : 定义控制台应用程序的入口点。
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
int p,n,sum;
int mat[305][305];
int linker[305];
int vis[305];
int dfs(int x)
{
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i]&&mat[x][i]==1)
		{
			vis[i]=1;
			if(linker[i]==-1||dfs(linker[i]))
			{
				linker[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
void xiongyali()
{
	for(int i = 1;i<=p;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			sum++;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&p,&n);
		memset(mat,0,sizeof(mat));
		for(int i = 1;i<=p;i++)
		{
			int m;
			scanf("%d",&m);
			while(m--)
			{
				int x;
				scanf("%d",&x);
				mat[i][x]=1;
			}
		}
		memset(linker,-1,sizeof(linker));
		sum = 0;
		xiongyali();
		if(sum==p) cout<<"YES"<<endl;  
        else cout<<"NO"<<endl; 
	}
}

