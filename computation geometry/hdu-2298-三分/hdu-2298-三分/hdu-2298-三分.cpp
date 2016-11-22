// hdu-2298-����.cpp : �������̨Ӧ�ó������ڵ㡣
//Bob�ڣ�0��0���������ڣ�x, y)���ˮ������ʼ���ٶ�Ϊv(��֪), g=9.8, ����С�ĽǶ��䵽ƻ��. 
/*
1> x=vcos��* t   ----����---> t=x/vcos��

2> y=vsin��*t -g*t*t/2 ����1��
y = f(t)=x*tan(t)-g*x*x/2(v*cos(t))^2,����t��ʾv��x������ļнǣ����ȣ�
 
�ú��������䣨0,��/2)������������������ǿ����ڸ����������֣����ʹ����ȡ�ü���ֵ�ĽǶ�t0����f(t0)<y�����޽⣻��������䣨0��t0�����֣��ҵ�ʹ��f(t)=y��tֵ����Ϊ����
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
  
double three_devide(double low,double up)  //���������
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

