// hdu-1180-bfs.cpp : 定义控制台应用程序的入口点。
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
char map[30][30];
int vis[30][30];
int n,m;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int sx,sy;
struct Node
{
	int x,y,d;
};
int judge(int x,int y)  
{  
    if(x<0||x>=n||y<0||y>=m)  
        return 0;  
    if(map[x][y]=='*')  
        return 0;  
    if(vis[x][y])  
        return 0;  
    return 1;  
} 
int bfs(int sx,int sy)
{
	memset(vis,0,sizeof(vis));
	vis[sx][sy]=1;
	queue<Node> Q;
	Node st;
	st.x = sx;
	st.y = sy;
	st.d = 0;
	Q.push(st);
	while(!Q.empty())
	{
		Node cur = Q.front();
		Q.pop();
		if(map[cur.x][cur.y]=='T')
			return cur.d;
		for(int i = 0;i<4;i++)
		{
			int nx = cur.x+dir[i][0];
			int ny = cur.y+dir[i][1];
			if(nx<0||nx>=n||ny<0||ny>=m)
				continue;
			if(vis[nx][ny]||map[nx][ny]=='*')
				continue;
			else if(map[nx][ny]=='.'||map[nx][ny]=='T')
			{
				Node nn;
				nn.x = nx;
				nn.y = ny;
				nn.d = cur.d+1;
				vis[nx][ny]=1;
				Q.push(nn);
			}
			else
			{
				if(i==0||i==1)
				{
					if(map[nx][ny]=='|'&&cur.d%2==0)
					{
						Node nn;
						nn.x = nx+dir[i][0];
						nn.y = ny+dir[i][1];
						if(judge(nn.x,nn.y))
						{
							nn.d = cur.d+1;
							vis[nn.x][nn.y]=1;
							Q.push(nn);
						}
					}
					else if(map[nx][ny]=='-'&&cur.d%2==1)
					{
						Node nn;
						nn.x = nx+dir[i][0];
						nn.y = ny+dir[i][1];
						if(judge(nn.x,nn.y))
						{
							nn.d = cur.d+1;
							vis[nn.x][nn.y]=1;
							Q.push(nn);
						}
					}
					else
					{
						Node nn;
						nn.x = cur.x;
						nn.y = cur.y;
						nn.d = cur.d+1;
						Q.push(nn);
					}
				}
				else
				{
					if(map[nx][ny]=='|'&&cur.d%2==1)
					{
						Node nn;
						nn.x = nx+dir[i][0];
						nn.y = ny+dir[i][1];
						if(judge(nn.x,nn.y))
						{
							nn.d = cur.d+1;
							vis[nn.x][nn.y]=1;
							Q.push(nn);
						}
					}
					else if(map[nx][ny]=='-'&&cur.d%2==0)
					{
						Node nn;
						nn.x = nx+dir[i][0];
						nn.y = ny+dir[i][1];
						if(judge(nn.x,nn.y))
						{
							nn.d = cur.d+1;
							vis[nn.x][nn.y]=1;
							Q.push(nn);
						}
					}
					else
					{
						Node nn;
						nn.x = cur.x;
						nn.y = cur.y;
						nn.d = cur.d+1;
						Q.push(nn);
					}
				}
			}
		}
	}
	return -1;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        int i; 
        for(i=0;i<n;i++)  
        {  
            scanf("%s",map[i]);  
            int j;  
            for(j=0;j<m;j++)  
            {  
                if(map[i][j]=='S')  
                    sx=i,sy=j;  
            }  
        }  
        int res=bfs(sx,sy);  
        printf("%d\n",res);  
    }  
    return 0; 
}

