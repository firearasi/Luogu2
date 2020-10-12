// P1379.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef pair<string, int> Board;
class Solution
{
    Board start;
    Board end;
    map<string, int>visitInfo;

    bool getExchangeDirection(Board input, int dir, Board& output)
    {
        if (dir == 0)
        {
            if (input.second % 3 == 0)
            {
                return false;
            }
            else
            {
                output.first = input.first;
                swap(output.first[input.second], output.first[input.second - 1]);
                output.second = input.second - 1;
                return true;
            }
        }
        else if (dir == 1)
        {
            if (input.second < 3)
            {
                return false;
            }
            else
            {
                output.first = input.first;
                swap(output.first[input.second], output.first[input.second - 3]);
                output.second = input.second - 3;
                return true;
            }

        }
        else if (dir == 2)
        {
            if (input.second % 3 == 2)
            {
                return false;
            }
            else
            {
                output.first = input.first;
                swap(output.first[input.second], output.first[input.second + 1]);
                output.second = input.second + 1;
                return true;
            }
        }
        else if (dir == 3)
        {
            if (input.second >= 6 )
            {
                return false;
            }
            else
            {
                output.first = input.first;
                swap(output.first[input.second], output.first[input.second + 3]);
                output.second = input.second + 3;
                return true;
            }
        }


        return false;
    }

public:
    Solution(string st,string en="123804765")
    {
        start.first = st;
        start.second = st.find_first_of('0');
        end.first = en;
        end.second = en.find_first_of('0');
    }
    int solve()
    {
        if (start.first == end.first)
        {
            return 0;
        }

        int ds = 0, de = 0;
        queue<Board> ques;
        ques.push(start);
        visitInfo[start.first] = 1;

        queue<Board> quee;
        quee.push(end);
        visitInfo[end.first] = 2;

        while (!ques.empty() && !quee.empty())
        {
            ds++;
            int cnts = ques.size();
            while (cnts--)
            {
                Board node = ques.front(); ques.pop();
                Board nbr;
                for (int k = 0; k < 4; k++)
                {
                    if (getExchangeDirection(node, k, nbr))
                    {
                        if (!visitInfo.count(nbr.first))
                        {
                            visitInfo[nbr.first] = 1;
                            ques.push(nbr);
                        }
                        if (visitInfo[nbr.first] == 2)
                        {
                            return ds + de;
                        }
                        
                    }
                }
            }
            de++;
            int cnte = quee.size();

            while (cnte--)
            {
                Board node = quee.front(); quee.pop();
                Board nbr;
                for (int k = 0; k < 4; k++)
                {
                    if (getExchangeDirection(node, k, nbr))
                    {
                        if (!visitInfo.count(nbr.first))
                        {
                            visitInfo[nbr.first] = 2;
                            quee.push(nbr);
                        }
                        if (visitInfo[nbr.first] == 1)
                        {
                            return ds + de;
                        }

                    }
                }
            }

        }
        return -1;
    }
};

int main()
{
    string st,en;
    cin >> st >> en;

    Solution sol(st, en);
    
    cout << sol.solve() << endl;
}
