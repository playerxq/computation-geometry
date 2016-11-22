// hdu-1198-并查集.cpp : 定义控制台应用程序的入口点。
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
struct Node
{
	int up,down,left,right;
};
int m,n;
Node map[55][55];
int vis[55][55];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int ok(int nx,int ny,int d)
{
	if(nx<0||nx>=m||ny<0||ny>=n)
		return 0;
	if(d==0&&map[nx][ny].down==0)
		return 0;
	if(d==1&&map[nx][ny].up==0)
		return 0;
	if(d==2&&map[nx][ny].right==0)
		return 0;
	if(d==3&&map[nx][ny].left==0)
		return 0;
	return 1;
}
void dfs(int x, int y)
{
	if(vis[x][y])
		return;
	vis[x][y]=1;
	for(int i = 0;i<4;i++)
	{
		if(map[x][y].up==0&&i==0)
			continue;
		if(map[x][y].down==0&&i==1)
			continue;
		if(map[x][y].left==0&&i==2)
			continue;
		if(map[x][y].right==0&&i==3)
			continue;
		int nx = x+dir[i][0];
		int ny = y + dir[i][1];
		if(ok(nx,ny,i))
			dfs(nx,ny);
	}
}
int cal()
{
	int cnt = 0;
	for(int i = 0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(!vis[i][j])
			{
				cnt++;
				dfs(i,j);
			}
		}
	}
	return cnt;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	char s[55];
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==-1&&n==-1)
			break;
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<m;i++)
		{
			scanf("%s",s);
			for(int j = 0;j<n;j++)
			{
				if(s[j]=='A')
				{
					map[i][j].up = 1;
					map[i][j].left = 1;
				}
				else if(s[j]=='B')
				{
					map[i][j].up = 1;
					map[i][j].right = 1;
				}
				else if(s[j]=='C')
				{
					map[i][j].down = 1;
					map[i][j].left = 1;
				}
				else if(s[j]=='D')
				{
					map[i][j].down = 1;
					map[i][j].right = 1;
				}
				else if(s[j]=='E')
				{
					map[i][j].up = 1;
					map[i][j].down = 1;
				}
				else if(s[j]=='F')
				{
					map[i][j].right = 1;
					map[i][j].left = 1;
				}
				else if(s[j]=='G')
				{
					map[i][j].up = 1;
					map[i][j].left = 1;
					map[i][j].right = 1;
				}
				else if(s[j]=='H')
				{
					map[i][j].up = 1;
					map[i][j].down = 1;
					map[i][j].left = 1;
				}
				else if(s[j]=='I')
				{
					map[i][j].down = 1;
					map[i][j].left = 1;
					map[i][j].right = 1;
				}
				else if(s[j]=='J')
				{
					map[i][j].up = 1;
					map[i][j].down = 1;
					map[i][j].right = 1;
				}
				else if(s[j]=='K')
				{
					map[i][j].up = 1;
					map[i][j].down = 1;
					map[i][j].left = 1;
					map[i][j].right = 1;
				}
			}
		}
		int res = cal();
		printf("%d\n",res);
	}
}

