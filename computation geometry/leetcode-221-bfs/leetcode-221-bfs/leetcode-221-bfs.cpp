// leetcode-221-bfs.cpp : 定义控制台应用程序的入口点。
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

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.size()==0)
			return 0;
        int r = matrix.size();
		int c = matrix[0].size();
		vector<vector<char>> ve;
		int maxxarea = 0;
		ve.push_back(matrix[0]);
		for(int k = 0;k<c;k++)
		{
			if(ve[0][k]=='1')
			{
				maxxarea = 1;
				break;
			}
		}
		for(int i = 1;i<r;i++)
		{
			int st = ve.size()-i;
			int ed = ve.size();
			for(int j = st;j<ed;j++)
			{
				int cnt = 0;
				int maxx = 0;
				vector<char> tmp(c);
				for(int k = 0;k<c;k++)
				{
					tmp[k] = ((matrix[i][k]-'0')&(ve[j][k]-'0'))+'0';
					if(tmp[k]=='0')
					{
						maxx = maxx>cnt?maxx:cnt;
						cnt = 0;
					}
					else
						cnt++;
				}
				maxx = maxx>cnt?maxx:cnt;
				maxxarea = ((i-(j-st)+1)<=maxx)?max(((i-(j-st)+1)*(i-(j-st)+1)),maxxarea):maxxarea;
				ve.push_back(tmp);
			}
			for(int k = 0;k<c;k++)
			{
				if(matrix[i][k]=='1')
				{
					maxxarea = max(maxxarea,1);
					break;
				}
			}
			ve.push_back(matrix[i]);
		}
		return maxxarea;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<vector<char>> vv;
	vector<char> v1;
	v1.push_back('0');
	v1.push_back('0');
	v1.push_back('0');
	//v1.push_back('0');
	//v1.push_back('0');
	vv.push_back(v1);
	vector<char> v2;
	v2.push_back('0');
	v2.push_back('0');
	v2.push_back('0');
	//v2.push_back('1');
	//v2.push_back('1');
	vv.push_back(v2);
	
	vector<char> v3;
	v3.push_back('1');
	v3.push_back('1');
	v3.push_back('1');
	//v3.push_back('1');
	//v3.push_back('1');
	vv.push_back(v3);
	/*
	vector<char> v4;
	v4.push_back('1');
	v4.push_back('0');
	v4.push_back('0');
	v4.push_back('1');
	v4.push_back('0');
	vv.push_back(v4);
	*/
	s.maximalSquare(vv);
	return 0;
}

