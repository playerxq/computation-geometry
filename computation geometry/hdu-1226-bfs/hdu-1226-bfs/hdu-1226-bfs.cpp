// hdu-1226-bfs.cpp : 定义控制台应用程序的入口点。
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
const int N = 5005;
const int M = 20;
int n,m,c;
bool flag[5005];
char dig[M];
struct node
{
    int r,num;
    char s[501];
}ss,now;
queue<node> que;
int getdig(int i)
{
    if(dig[i] >= 'A')
        return dig[i] - 'A' + 10;
    else
        return dig[i] - '0';
}
void bfs()
{
	memset(flag,false,sizeof(flag));
	ss.num=ss.r=0;
	que.push(ss);
	while(!que.empty())
	{
		now = que.front();
		que.pop();
		if(now.num>=500)
			break;
		for(int i = 0;i<m;i++)
		{
			if(now.num==0&&dig[i]=='0')
				continue;
			ss = now;
            ss.r = now.r * c + getdig(i);
            ss.r %= n;
            ss.s[ss.num ++] = dig[i];
			if(ss.r == 0)
            {
                ss.s[ss.num] = '\0';
                puts(ss.s);
                return;
            }
			if(!flag[ss.r])
			{
					flag[ss.r]=true;
					que.push(ss);
			}
		}
	}
	puts("give me the bomb please");
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i,t;
    char ch;
    scanf("%d",&t);
    while(t --)
    {
		while(!que.empty())
			que.pop();
        scanf("%d%d%d",&n,&c,&m);
        for(i = 0;i < m;i ++)
        {
            while(isspace((ch = getchar())))
                ;
            dig[i] = ch;
        }
        dig[m] = '\0';
        if(n == 0)
        {
            if(dig[0] == '0')
                puts("0");
            else
                puts("give me the bomb please");
            continue;
        }
        sort(dig,dig + m);
        bfs();
    }
    return 0;
}

