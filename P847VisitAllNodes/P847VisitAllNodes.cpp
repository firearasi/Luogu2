#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
    set<pair<int, int>> used;
    int visited;
    int curNode;
    int minimum;
    int visitedNum;
    void dfs(int cur, vector<vector<int>>& graph)
    {
        bool finished = true;
        if (minimum-(cur-1)<graph.size()-visitedNum)
        {
            return;
        }
        if (visited == numeric_limits<int>::max())
        {
            minimum = min(minimum, cur - 1);
            return;
        }
        if (cur == 0)
        {
            for (int i = 0; i < graph.size(); i++)
            {
                int flag = 1 << i;
                visited |= flag;
                visitedNum = 1;
                curNode = i;
                dfs(cur + 1, graph);
                visited &= ~flag;
                visitedNum = 0;
            }
        }
        else
        {
            for (int nextNode : graph[curNode])
            {
                if (!used.count({ curNode,nextNode }))
                {
                    int flag = 1 << nextNode;
                    int oldVisited = visited & flag;
                    int oldCurNode = curNode;
                    if (oldVisited == 0)
                    {
                        visited |= flag;
                        visitedNum++;
                    }
                    used.insert({ curNode,nextNode });
                    curNode = nextNode;
                    dfs(cur + 1, graph);

                    used.erase({ oldCurNode,nextNode });
                    if (oldVisited == 0)
                    {
                        visited &= ~flag;
                        visitedNum--;
                    }
                }
            }
        }
    }

    int solve(vector<vector<int>>& graph)
    {
        visited = numeric_limits<int>::max();
        visitedNum = 0;
        int flag = 1;
        for (int i = 0; i < graph.size(); i++)
        {
            visited &= ~flag;
            flag <<= 1;
        }
        minimum = numeric_limits<int>::max();

        dfs(0, graph);
        return minimum;
    }


public:
    int shortestPathLength(vector<vector<int>>& graph) {
        return solve(graph);
    }
};
int main()
{
    Solution sol;
    vector<vector<int>> graph = { {1, 4}, {0, 3, 4, 7, 9}, {6, 10}, {1, 10}, {1, 0}, {6}, {7, 2, 5}, {6, 1, 8}, {7}, {1}, {2, 3} };
    cout << sol.shortestPathLength(graph) << endl;
}
