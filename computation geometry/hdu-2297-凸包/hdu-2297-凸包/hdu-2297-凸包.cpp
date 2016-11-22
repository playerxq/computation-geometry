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
#define N 50010
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
struct point
{
    double x,y;
    point(double x=0,double y =0 ):x(x),y(y){}
}p[N],ch[N];
typedef point pointt;
point operator -(point a,point b)
{
    return point(a.x-b.x,a.y-b.y);
}
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}
double mul(point p0,point p1,point p2)
{
    return cross(p1-p0,p2-p0);
}
double dis(point a)
{
    return sqrt(a.x*1.0*a.x+a.y*1.0*a.y);
}
bool cmp(point a,point b)
{
    if(dcmp(mul(p[0],a,b))==0)//p[0],a,b¹²Ïß
        return dis(a-p[0])<dis(b-p[0]);
    else
        return dcmp(mul(p[0],a,b))>0;
}
int Graham(int n)
{
    if(n<2) return n;
    int i,k = 0,top;
    point tmp;
    for(i = 0 ; i < n; i++)
    {
        if(p[i].y<p[k].y||(p[i].y==p[k].y&&p[i].x<p[k].x))
            k = i;
    }
    if(k!=0)
    {
        tmp = p[0];
        p[0] = p[k];
        p[k] = tmp;
    }
    sort(p+1,p+n,cmp);
    ch[0] = p[0];
    ch[1] = p[1];
    top = 1;
    for(i = 2; i < n ; i++)
    {
        while(top>0&&dcmp(mul(ch[top-1],ch[top],p[i]))<=0)
            top--;
        top++;
        ch[top] = p[i];
    }
    return top;
}
int main()
{
    int t,i,n;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0 ; i < n; i++)
        scanf("%lf%lf",&p[i].y,&p[i].x);
        int m = Graham(n);
        int maxx = -INF,tx,maxy = -INF,ty;
        if(n<2)
        {
            cout<<"1\n";
            continue;
        }
        for(i = 0 ; i <= m ; i++)
        {
            //cout<<ch[i].x<<" "<<ch[i].y<<endl;
            if(ch[i].x>maxx)
            {
                tx = i;
                maxx = ch[i].x;
            }
            if(ch[i].y>maxy)
            {
                ty = i;
                maxy = ch[i].y;
            }
        }
        cout<<ty-tx+1<<endl;
    }
    return 0;
}