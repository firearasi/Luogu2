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
	int n, k;
	int tot;
	int sum;

	vector<int> arr;
public:
	Solution(int _n, int _k) :n(_n), k(_k), tot(0), sum(0)
	{
		arr = vector<int>(n);
	}
	void readData()
	{
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
	}

	bool isPrime(int n)
	{
		if (n <= 1)
		{
			return false;
		}
		if ( n == 2)
		{
			return true;
		}
		for (int i = 2; i <= floor(sqrt(n) + 0.5); i++) {
			if (n % i == 0)
				return false;
		}
		return true;
	}
	void solve(int cur, int maxIndex)
	{
		if (cur == k) {
			if (isPrime(sum))
			{
				tot++;
			}
		}
		else
		{
			for (int i = maxIndex+1; i < n; i++)
			{
				
				
					sum += arr[i];
					solve(cur + 1,i);
					sum -= arr[i];
				
			}
		}
		
	}

	int solve()
	{
		solve(0,-1);
		return tot;
	}
};

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		Solution sol(n, k);
		sol.readData();
		cout << sol.solve() << endl;
	}
}

