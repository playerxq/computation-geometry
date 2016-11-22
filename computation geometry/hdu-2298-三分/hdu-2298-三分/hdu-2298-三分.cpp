// hdu-2298-三分.cpp : 定义控制台应用程序的入口点。
//Bob在（0，0）点想射在（x, y)点的水果，初始的速度为v(已知), g=9.8, 求最小的角度射到苹果. 
/*
1> x=vcosθ* t   ----变形---> t=x/vcosθ

2> y=vsinθ*t -g*t*t/2 代入1有
y = f(t)=x*tan(t)-g*x*x/2(v*cos(t))^2,其中t表示v与x轴正向的夹角（弧度）
 
该函数在区间（0,π/2)上先增后减，所以我们可以在该区间上三分，求出使函数取得极大值的角度t0。若f(t0)<y，则无解；否则对区间（0，t0）二分，找到使得f(t)=y的t值，即为所求。
*/
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
const double eps=1.0e-9;  
const double PI=acos(-1.0);  
const double g=9.8;  
double x,y,v;  
  
double f(double t)  
{  
    return x*tan(t)-g*x*x/2/(v*v*cos(t)*cos(t));  
}  
  
double two_devide(double low,double up)  
{  
    double m;  
    while(up-low>=eps)  
    {  
        m=(up+low)/2;  
        if(f(m)<=y)  
            low=m;  
        else  
            up=m;  
    }  
    return m;  
}  
  
double three_devide(double low,double up)  //三分找最大
{  
    double m1,m2;  
    while(up-low>=eps)  
    {  
        m1=low+(up-low)/3;  
        m2=up-(up-low)/3;  
        if(f(m1)<=f(m2))  
            low=m1;  
        else  
            up=m2;  
    }  
    return (m1+m2)/2;  
}  
  
int main()  
{  
    int t;  
    double maxt;  
    cin>>t;  
    while(t--)  
    {  
        cin>>x>>y>>v;  
        maxt=three_devide(0,PI/2);  
        if(f(maxt)<y)  
            printf("-1\n");  
        else  
            printf("%.6lf\n",two_devide(0,maxt));  
    }  
    return 0;  
} 

