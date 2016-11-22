// hdu-2290-floyd.cpp : 定义控制台应用程序的入口点。
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
const long long Inf = 40000000;
int dp[210][210][210];//dp[i][j][k]从i到j使用1:k中转
int mp[210][210];
int dx[210];
int N,M,Q;
struct node
{
	int C;
	int dx;
	friend bool operator<(node A,node B)
    {
        return A.C<B.C;
    }
};
node cops[210];
int T;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int a,b,c;
    scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&cops[i].C);//每个城市警察数目
            cops[i].dx = i;//关联索引
        }
		sort(cops,cops+N);
		for(int i=0;i<N;i++)
        {
            dx[cops[i].dx] = i+1;//之前cops[i].dx城市的警察现在在i+1处  从1开始
        }
		for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                mp[i][j] = (i==j?0:Inf);
            }
        }
		for(int i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
             
            mp[dx[a]][dx[b]] = mp[dx[b]][dx[a]] = min(mp[dx[a]][dx[b]],c);
        }
		for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                dp[i][j][0] = mp[i][j];
            }
        }
		for(int k=1;k<=N;k++)//中转城市
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    dp[i][j][k] = dp[i][j][k-1];
                }
            }
 
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    if( dp[i][j][k]>dp[i][k][k-1]+dp[k][j][k-1] )
                    {
                         dp[i][j][k] = dp[i][k][k-1]+dp[k][j][k-1];//1:k中转由1:k-1中转flyod计算
                    }
                }
            }
        }
		scanf("%d",&Q);
		while(Q--)
        {
            scanf("%d %d %d",&a,&b,&c);
            a = dx[a];
            b = dx[b];
            int ans = Inf;
            ans = min(ans,dp[a][b][0]);
            for(int i=N-1;i>=0;i--)//枚举中转城市 且每个城市的警察数目不超过c 从最大警察数目的N-1号开始  若找到一个i号小于c 则i号之前都城市都满足
            {
                if( cops[i].C<=c )//i号可以作为中转  即可以用0:i中转 dp计算从1开始故为1:i+1
                {
                    ans = min(ans,dp[a][b][i+1]);
                    break;//i+1到1号都可以
                }
            }
             
            if( ans==Inf )
                printf("-1\n");
            else
                printf("%d\n",ans);
        }
        printf("\n");
	}
}

