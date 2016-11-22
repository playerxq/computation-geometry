// hdu-2290-floyd.cpp : �������̨Ӧ�ó������ڵ㡣
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
int dp[210][210][210];//dp[i][j][k]��i��jʹ��1:k��ת
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
            scanf("%d",&cops[i].C);//ÿ�����о�����Ŀ
            cops[i].dx = i;//��������
        }
		sort(cops,cops+N);
		for(int i=0;i<N;i++)
        {
            dx[cops[i].dx] = i+1;//֮ǰcops[i].dx���еľ���������i+1��  ��1��ʼ
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
		for(int k=1;k<=N;k++)//��ת����
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
                         dp[i][j][k] = dp[i][k][k-1]+dp[k][j][k-1];//1:k��ת��1:k-1��תflyod����
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
            for(int i=N-1;i>=0;i--)//ö����ת���� ��ÿ�����еľ�����Ŀ������c ����󾯲���Ŀ��N-1�ſ�ʼ  ���ҵ�һ��i��С��c ��i��֮ǰ�����ж�����
            {
                if( cops[i].C<=c )//i�ſ�����Ϊ��ת  ��������0:i��ת dp�����1��ʼ��Ϊ1:i+1
                {
                    ans = min(ans,dp[a][b][i+1]);
                    break;//i+1��1�Ŷ�����
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

