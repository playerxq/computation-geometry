// hdu-1175-dfs.cpp : 定义控制台应用程序的入口点。
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
int n,m;
int map[1003][1003];
int wan[1003][1003];
const int dirx[5] = {0,0,1,0,-1};  
const int diry[5] = {0,1,0,-1,0}; 
int ax,ay,bx,by;
int mark;
int yes(int x, int y, int dir)
{
	int dx = bx-x;
	int dy = by-y;
	if(dx!=0)
		dx = dx/abs(dx);
	if(dy!=0)
		dy = dy/abs(dy);
	if(dx==dirx[dir]&&dy==diry[dir])
		return 1;
	return 0;
}
void dfs(int x, int y, int cnt, int dir)
{
	if(mark)
		return;
	if(cnt>2||x<1||x>n||y<1||y>m)
		return;
	if(x==bx&&y==by)
	{
		mark = 1;
		return;
	}
	if(cnt==2&&!yes(x,y,dir))
		return;
	if(map[x][y]!=0)
		return;
	if(wan[x][y]<=cnt&&wan[x][y]!=-1)
		return;
	wan[x][y]=cnt;
	for(int i = 1;i<=4;i++)
	{
		int tx = x+dirx[i];
		int ty = y+diry[i];
		if(i!=dir)
			dfs(tx,ty,cnt+1,i);
		else
			dfs(tx,ty,cnt,i);
	}
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n+m==0)
			break;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		int t;
		scanf("%d",&t);
		while(t--)
		{
			mark = 0;
			memset(wan,-1,sizeof(wan)); 
			scanf("%d%d%d%d",&ax,&ay,&bx,&by);
			if(map[ax][ay]!=map[bx][by]||map[ax][ay]==0)
			{
				printf("NO\n");
				continue;
			}
			wan[ax][ay]=0;
			for(int i = 1;i<=4;i++)
			{
				dfs(ax+dirx[i],ay+diry[i],0,i);
			}
			if(mark)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}

