#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    int m, n;
    string s, t;
    vector<vector<int>> d;

    int dfs(int i, int j)
    {
      
        int& ans = d[i][j];
        if (ans != -1) return ans;
        if (i < j)
        {
            ans = 0;
        }
        else if (i == j)
        {
            ans = (int)(s.substr(0, i) == t.substr(0, j));
        }
        else
        {
            if (j == 1)
            {
                ans = 0;
                for (int k = 0; k < i; k++)
                {
                    if (s[k] == t[0])
                    {
                        ans++;
                    }
                }
            }
            else
            {
                //cout << "here" << endl;
                ans = dfs(i - 1, j);
                if (s[i - 1] == t[j - 1])
                    ans += dfs(i - 1, j - 1);
            }
        }
        cout << i<<" "<<s.substr(0,i) << "," << j<<" "<<t.substr(0,j) << ": " << ans << endl;
        return ans;
    }

public:
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        m = s.size();
        n = t.size();
        d = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return dfs(m, n);
    }
};

int main()
{
    string s = "babgbag";
    string t = "bag";
    Solution sol;
    cout << sol.numDistinct(s, t) << endl;
}