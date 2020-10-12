// P1036.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution
{
	int n;
	
	vector<int> arr;
public:
	Solution(int _n) :n(_n)
	{
		arr = vector<int>(n);
	}
	


	void solve(int cur)
	{
		if (cur == n) {
			for (int i = 0; i < n; i++)
			{
				printf("%5d", arr[i]);
			}
			printf("\n");
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				bool ok = true;
				for (int j = 0; j < cur; j++)
				{
					if (i == arr[j])
					{
						ok = false;
					}
				}
				if (ok)
				{
					arr[cur] = i;
					solve(cur + 1);
				}
				
			}
		}

	}

	void solve()
	{
		solve(0);
	}
};

int main()
{
	std::ios::sync_with_stdio(0);
	int n, k;
	while (cin >> n)
	{
		Solution sol(n);
		sol.solve();
	}
}

