#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    vector<string> collection;
    string pattern;
    int diff = 0;
    void solve(int cur, int n)
    {
        if (cur == 2*n && diff == 0)
        {
            collection.push_back(pattern);
        }
         else if(diff>2*n-cur)
         {
             return;
         }
        else
        {
            pattern[cur] = '(';
            diff++;
            solve(cur + 1, n);
            diff--;

            if (diff)
            {
                pattern[cur] = ')';
                diff--;
                solve(cur + 1, n);
                diff++;
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {

        pattern = string(2*n, '0');
        collection.clear();
        solve(0, n);
        return collection;
    }
};



int main()
{
    Solution sol;
    auto res = sol.generateParenthesis(3);


}