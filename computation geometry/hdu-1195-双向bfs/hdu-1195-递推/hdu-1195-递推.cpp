// hdu-1195-递推.cpp : 定义控制台应用程序的入口点。
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
int n;
char s[5];
int flag;
int vis1[10][10][10][10];
int vis2[10][10][10][10];
struct node
{
	int step;
	int a[5];
};
node first,last;
int get_step(int a, int b)
{
	if((a==1&&b==9)||(a==9&&b==1))
		return 1;
	return abs(a-b);
}
void bfs()
{
	int i,k,temp1,temp2;  
    node  qf, ql, pf, pl;  
    queue<node>  Q1,  Q2;
	memset(vis1,-1,sizeof(vis1));
	memset(vis2,-1,sizeof(vis2));
	flag = 1;
	first.step=0;  
	first.step=0; pf=first;  
    last.step=0; pl=last;
    vis1[pf.a[0]][pf.a[1]][pf.a[2]][pf.a[3]]=0;  
    vis2[pl.a[0]][pl.a[1]][pl.a[2]][pl.a[3]]=0;
	Q1.push(pf);Q2.push(pl);
	temp1 = temp2 = 0;
	while(1)
	{
		while(!Q1.empty()&&Q1.front().step==temp1)
		{
			pf=Q1.front(); Q1.pop();
			if((k=vis2[pf.a[0]][pf.a[1]][pf.a[2]][pf.a[3]])!=-1)
			{
				printf("%d\n",pf.step+k);  
                return;
			}
			for(i=0;i<4;i++)//+1;  
            {  
                qf=pf;  
                if(pf.a[i]==9) qf.a[i]=1;  
                else qf.a[i]=pf.a[i]+1;  
                qf.step=pf.step+1;  
                if((k=vis2[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]])!=-1)//判断是否反搜过  
                {  
                    printf("%d\n",qf.step+k);  
                    return;  
                }  
                if(vis1[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]]==-1)  
                {  
                    vis1[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]]=qf.step;  
                    Q1.push(qf);  
                }  
            }  
            for(i=0;i<4;i++)//-1;  
            {  
                qf=pf;  
                if(pf.a[i]==1) qf.a[i]=9;  
                else qf.a[i]=pf.a[i]-1;  
                qf.step=pf.step+1;  
                if((k=vis2[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]])!=-1)  
                {  
                    printf("%d\n",qf.step+k);  
                    return;  
                }  
                if(vis1[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]]==-1)  
                {  
                    vis1[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]]=qf.step;  
                    Q1.push(qf);  
                }  
            }  
            for(i=0;i<3;i++)  
            {  
                qf=pf;  
                qf.a[i]=pf.a[i+1];  
                qf.a[i+1]=pf.a[i];  
                qf.step=pf.step+1;  
                if((k=vis2[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]])!=-1)  
                {  
                    printf("%d\n",qf.step+k);  
                    return;  
                }  
                if(vis1[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]]==-1)  
                {  
                    vis1[qf.a[0]][qf.a[1]][qf.a[2]][qf.a[3]]=qf.step;  
                    Q1.push(qf);  
                }  
            }
		}
		temp1=Q1.front().step;
		while(!Q2.empty()&&Q2.front().step==temp2)//反搜；  
        {  
            pl=Q2.front();Q2.pop();  
            if((k=vis1[pl.a[0]][pl.a[1]][pl.a[2]][pl.a[3]])!=-1)  
            {  
                printf("%d\n",pl.step+k);  
                return;  
            }  
            for(i=0;i<4;i++)//+1;  
            {  
                ql=pl;  
                if(pl.a[i]==9) ql.a[i]=1;  
                else ql.a[i]=pl.a[i]+1;  
                ql.step=pl.step+1;  
                if((k=vis1[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]])!=-1)  
                {  
                    printf("%d\n",ql.step+k);  
                    return;  
                }  
                if(vis2[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]]==-1)  
                {  
                    vis2[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]]=ql.step;  
                    Q2.push(ql);  
                }  
            }  
            for(i=0;i<4;i++)//-1;  
            {  
                ql=pl;  
                if(pl.a[i]==1) ql.a[i]=9;  
                else ql.a[i]=pl.a[i]-1;  
                ql.step=pl.step+1;  
                if((k=vis1[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]])!=-1)  
                {  
                    printf("%d\n",ql.step+k);  
                    return;  
                }  
                if(vis2[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]]==-1)  
                {  
                    vis2[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]]=ql.step;  
                    Q2.push(ql);  
                }  
            }  
            for(i=0;i<3;i++)//相邻交换  
            {  
                ql=pl;  
                ql.a[i]=pl.a[i+1];  
                ql.a[i+1]=pl.a[i];  
                ql.step=pl.step+1;  
                if((k=vis1[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]])!=-1)  
                {  
                    printf("%d\n",ql.step+k);  
                    return;  
                }  
                if(vis2[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]]==-1)  
                {  
                    vis2[ql.a[0]][ql.a[1]][ql.a[2]][ql.a[3]]=ql.step;  
                    Q2.push(ql);  
                }  
            }  
        }  
        temp2=Q2.front().step; 
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int cas,i;  
    char chf[5],chl[5];  
    scanf("%d",&cas);  
    while(cas--)  
    {  
       scanf("%s%s",chf,chl);  
       for(i=0;i<4;i++)  
       {  
          first.a[i]=chf[i]-'0';  
          last.a[i]=chl[i]-'0';  
       }  
       bfs();  
    }  
    return 0; 
}

