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
int T, M;
vector<vector<int>> d;
vector<pair<int, int>> medecine;

int dfs(int t,int i)
{
	if (t <= 0)
	{
		return 0;
	}
	int& ans = d[t][i];
	if (ans != -1) return ans;
	
	if (i == M - 1)
	{
		if (t >= medecine[i].first)
		{
			ans = medecine[i].second;
		}
		else
		{
			ans = 0;
		}
	}
	else 
	{
		ans = dfs(t, i + 1);
		if (t >= medecine[i].first)
		{
			ans = max(ans, medecine[i].second + dfs(t - medecine[i].first, i + 1));
		}
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	freopen("c:\\input\\P1048.txt", "r", stdin);
	while (cin >> T >> M)
	{
		medecine.clear();
		int a, b;
		int m = M;
		while (m--)
		{
			cin >> a >> b;
			medecine.push_back({ a,b });
		}
		d = vector<vector<int>>(T+1,vector<int>(M, -1));

		cout << dfs(T,0) << endl;
	}

}

