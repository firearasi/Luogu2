#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    unordered_map<int, unordered_set<int>> adj;
    map<pair<int, int>, int> price;
    vector<int> arr;
    vector<int> priceToNode;
    int cheapest = numeric_limits<int>::max();
    int s, d, k;
    int sum;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        arr.clear();
        arr.resize(n + 3);
        priceToNode = vector<int>(n, -1);
        for (auto& entry : flights)
        {
            adj[entry[0]].insert(entry[1]);
            price[{entry[0], entry[1]}] = entry[2];
        }
        s = src;
        d = dst;
        k = K;
        arr[0] = s;
        solve(1);
        return cheapest!=numeric_limits<int>::max()?cheapest:-1;
    }

    void solve(int cur)
    {
     
        if (arr[cur - 1] == d)
        {
            cheapest = min(cheapest, sum);
            //cout << "cheapest: " << cheapest << endl;
        }
        if (cur == k + 2)
        {
            return;
        }
       
        

        int node = arr[cur - 1];
        
        if (priceToNode[node] == -1 || priceToNode[node] > sum)
        {
            priceToNode[node] = sum;
        }
        else
        {
            return;
        }

        for (int i : adj[node])
        {
            cout << "cur: "<<cur<< " i: " << i << endl;
            sum += price[{node, i}];
            arr[cur] = i;
            solve(cur + 1);
            sum -= price[{node, i}];
        }

    }
};

int main()
{
    vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}, {3, 4, 1}};
    Solution sol;
    int s = sol.findCheapestPrice(5, flights, 0, 4, 2);
    cout << s << endl;
}