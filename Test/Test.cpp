// UVa1629CakeSlicing.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;
vector<pair<int, int>> cherries;



int main()
{
	std::ios::sync_with_stdio(false);
	freopen_s("c:\\input\\UVa1629.txt", "r", stdin);
	int m, n, k;
	int kase = 0;
	while (cin >> m >> n >> k)
	{
		cherries.clear();
		cherries.resize(k);
		for (int i = 0; i < k; i++)
		{
			cin >> cherries[k].first >> cherries[k].second;
		}
	}

}

