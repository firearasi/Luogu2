#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int n, m;
vector<long> d;
unordered_map<int, unordered_set<int>> adj;

long dfs(int i)
{
	long& ans = d[i];
	if (ans != -1) return ans;
	if (!adj.count(i))
	{
		ans = 1;
	}
	else
	{
		long maxLen = 1;
		for (int b : adj[i])
		{
			maxLen = max(maxLen, dfs(b));
		}
		ans = 1 + maxLen;
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("c:\\input\\P4017.txt", "r", stdin);
	while (cin >> n >> m)
	{
		d = vector<long>(n + 1, -1);
		adj.clear();
		int a, b;
		while (m--)
		{
			cin >> a >> b;
			adj[a].insert(b);
		}
		long maxLen = 1;
		for (int i = 1; i <= n; i++)
		{
			maxLen = max(maxLen, dfs(i));
		}
		cout << maxLen % 80112002 << endl;
	}
	
}

