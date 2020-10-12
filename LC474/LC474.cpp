#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    vector<pair<int, int>> vec;
    vector<vector<vector<int>>> d;
    //int tot1 = 0, tot2 = 0;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vec.clear();
        d = vector<vector<vector<int>>>(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        for (auto str : strs)
        {
            int a = 0, b = 0;
            for (auto c : str)
            {
                if (c == '0')
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
            vec.push_back({ a,b });
        }
        int res= solve(0, m, n);
        //cout << tot1 << " " << tot2  << endl;
        return res;
    }

    int solve(int i, int m, int n)
    {
        //tot1++;
        if (d[i][m][n]!=-1)
        {
            return d[i][m][n];
        }

        //tot2++;
      

        auto& pi = vec[i];

        if (i == vec.size() - 1)
        {
            d[i][m][n] = m >= pi.first && n >= pi.second;
        }
        else
        {

            int notInvolveI = solve(i + 1, m, n);
            int res;
            
            if (m >= pi.first && n >= pi.second)
            {
                res = max(notInvolveI, 1 + solve(i + 1, m - pi.first, n - pi.second));

            }
            else
            {
                res = notInvolveI;
            }

            //printf("d[%d,%d,%d]=%d\n", i, m, n, res);
            d[i][m][n] = res;
        }
        return  d[i][m][n];
    }
};

int main()
{
    vector<string> strs = { "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0", "1", "0" };

    Solution sol;
    int s = sol.findMaxForm(strs,30,30);
    cout << s << endl;
}