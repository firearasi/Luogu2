#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
int maxHeight;
vector<string> vocab;
int curLen;
int arr[16];
int used;

void solve(int cur)
{
	bool ended = true;
	for (int i = 0; i < vocab.size(); i++)
	{
		if (cur == 0 || ( (used&(1<<i))==0  && vocab[arr[cur - 1]].back() == vocab[i][0]))
		{
			ended = false;
			curLen += vocab[i].size();
			arr[cur] = i;
			used |= (1 << i);
			solve(cur + 1);
			int flag = ~(1 << i);
			used &= flag;
			curLen -= vocab[i].size();
		}
	}
	if (ended)
	{
		maxHeight = max(maxHeight, curLen);
	}
}


int main()
{
	std::ios::sync_with_stdio(false);
	freopen("c:\\input\\P1278.txt", "r", stdin);
	int N;
	while (cin >> N)
	{
		maxHeight = 0;
		vocab.clear();
		vocab.resize(N);
		used = 0;
		curLen = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> vocab[i];
		}
		solve(0);
		cout << maxHeight << endl;
	}
}
