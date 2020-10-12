// UVa1629CakeSlicing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;
int m, n, k;
vector<vector<int>> cherries;
int d[20][20][20][20];
int countD[21][21];


int count(int i, int j)
{
	int& ans = countD[i][j];
	if (ans != -1) return ans;

	if (i >= m || j >= n)
	{
		return ans = 0;
	}


	ans = (cherries[i][j] == 1) + count(i + 1, j) + count(i, j + 1) - count(i + 1, j + 1);
	return ans;
}


int count(int i0, int i1, int j0, int j1)
{
	
	return count(i0,j0)-count(i0,j1)-count(i1,j0)+count(i1,j1);
}



int solve(int i0, int i1, int j0, int j1, int num)
{
	tuple<int, int, int, int> tup = { i0,i1,j0,j1 };
	if (d[i0][i1][j0][j1] != -1)
	{
		return d[i0][i1][j0][j1];
	}

	if (count(i0, i1, j0, j1) <= 1)
	{
		d[i0][i1][j0][j1] = 0;
	}
	else
	{
		d[i0][i1][j0][j1] = numeric_limits<int>::max();
		for (int i = i0 + 1; i < i1 - 1; i++)
		{
			int c = count(i0, i, j0, j1);
			if (c && c < num)
				d[i0][i1][j0][j1] = min(d[i0][i1][j0][j1], j1 - j0 + solve(i0, i, j0, j1, c) + solve(i, i1, j0, j1, num - c));
		}
		for (int j = j0 + 1; j < j1 - 1; j++)
		{
			int c = count(i0, i1, j0, j);
			if (c && c < num)
				d[i0][i1][j0][j1] = min(d[i0][i1][j0][j1], i1 - i0 + solve(i0, i1, j0, j, c) + solve(i0, i1, j, j1, num - c));
		}
		if (d[i0][i1][j0][j1] == numeric_limits<int>::max())
		{
			d[i0][i1][j0][j1] = 0;
		}
	}

	return d[i0][i1][j0][j1];
}



int solve(int m, int n, int num)
{
	return solve(0, m, 0, n, num);
}

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("c:\\input\\UVa1629.txt", "r", stdin);

	int kase = 0;

	while (cin >> m >> n >> k)
	{
		memset(d, -1, 20 * 20 * 20 * 20 * sizeof(int));
		memset(countD, -1, sizeof(countD));
		
		cherries.clear();
		cherries = vector<vector<int>>(m, vector<int>(n, 0));
		int a, b;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;;
			cherries[a-1][b-1] = 1;
		}
		count(0, 0);
		cout << "Case " << ++kase << ": " << solve(m, n, k) << endl;
	}

}
