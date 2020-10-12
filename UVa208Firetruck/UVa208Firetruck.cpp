#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cstdio>
using namespace std;


class Graph
{
	int n,k;
	set<pair<int, int>> Edges;
	vector<int> parent;
	vector<int> fireroute;

	vector<int> canVisit;
	int tot = 0;
public:
	Graph(int _n,int _k) :n(_n),k(_k),parent(n+1),fireroute(n+1)
	{
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
		}
	}
	int Find(int x)
	{
		while (x != parent[x])
		{
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}

	void Connect(int i, int j)
	{
		if (i == j)
			return;
		
		if (i > j)
			swap(i, j);
		Edges.insert({ i,j });
		int rooti = Find(i);
		int rootj = Find(j);
		if (rooti == rootj)
		{
			return;
		}
	
		if (rooti < rootj)
		{
			parent[rootj] = rooti;
		}
		else
		{
			parent[rooti] = rootj;
		}
	}

	bool Connected(int i, int j)
	{
		return Find(i) == Find(j);
	}


	void printFireRoutes(int cur)
	{
		if (cur >= 1 && fireroute[cur - 1] == k)
		{
			tot++;
			for (int i = 0; i < cur - 1; i++)
			{
				cout << fireroute[i] << ' ';
			}
			cout << fireroute[cur - 1] << endl;
		}
		else 
		{
			int node = fireroute[cur - 1];
			for (int i : canVisit)
			{
				if (find(fireroute.begin(), fireroute.begin() + cur, i) == fireroute.begin() + cur && Edges.count({ min(node,i),max(node,i) }))
				{
					fireroute[cur] = i;
					printFireRoutes(cur + 1);
				}
			}
		}

	}

	void printFireRoutes()
	{

		for (int i = 1; i <= n; i++)
		{
			if (Connected(i, k))
			{
				canVisit.push_back(i);
			}
		}
		fireroute[0]=1;

		printFireRoutes(1);
		printf("There are %d routes from the firestation to streetcorner %d.\n", tot, k);
	}

};

int main()
{
	
	std::ios::sync_with_stdio(false);
	freopen("c:\\input\\UVa208Firetruck.txt", "r", stdin);
	int k;
	int kase = 0;
	while (cin >> k)
	{
		printf("Case %d:\n", ++kase);
		int a, b;
		int n = 1;
		vector<pair<int, int>> edges;
		//构建无向图和并查集
		do
		{
			cin >> a >> b;
			n = max(n, max(a, b));
			if (a >= 1 && b >= 1)
			{
				edges.push_back({ a,b });
			}
		} while (!(a == 0 && b == 0));
		Graph gr(n,k);
		for (auto& entry : edges)
		{
			gr.Connect(entry.first, entry.second);
		}
		gr.printFireRoutes();
		
	}
}

