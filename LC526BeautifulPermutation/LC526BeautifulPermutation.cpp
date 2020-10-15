#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
    int visited;
    int total;

    void backtrack(int cur, int n)
    {
        if (cur == n)
        {
            total++;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                int flag = 1 << i;
                if ( (visited & flag) == 0 && (cur % i == 0 || i % cur == 0))
                {
                    visited |= flag;
                    backtrack(cur + 1, n);
                    visited &= (~flag);
                }
            }
        }
    }
public:
    int countArrangement(int N) {
        visited = 0;
        total = 0;
        backtrack(0, N);
        return total;
    }
};

int main()
{
    Solution sol;
    cout << sol.countArrangement(3) << endl;


}