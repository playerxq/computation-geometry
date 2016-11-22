// hdu-1181-dfs.cpp : 定义控制台应用程序的入口点。
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
	int s,e;
} c[10000];
int vis[10000],l,flag;
void dfs(int cur)
{
	if(cur=='m'-'a')
		flag = 1;
	if(flag)
		return;
	for(int i = 0;i<l;i++)
	{
		if(vis[i])
			continue;
		if(c[i].s==cur)
		{
			vis[i]=1;
			dfs(c[i].e);
			vis[i]=0;
		}
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	char s[100];
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,"0")==0)
			continue;
		l = 0;
		c[l].s = s[0]-'a';
		c[l++].e = s[strlen(s)-1]-'a';
		while(scanf("%s",s)!=EOF&&strcmp(s,"0"))
		{
			c[l].s = s[0]-'a';
			c[l++].e = s[strlen(s)-1]-'a';
		}
		flag = 0;
		for(int i = 0;i<l;i++)
		{
			if(c[i].s==1)
			{
				memset(vis,0,sizeof(vis));
				vis[i]=1;
				dfs(c[i].s);
			}
			if(flag)
				break;
		}
		if(flag)  
            printf("Yes.\n");  
        else  
            printf("No.\n");
	}
}

