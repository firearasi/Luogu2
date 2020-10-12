// P1379.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution
{
    string start;
    string end;
    unordered_map<string, int> visitInfo;
    unordered_map<string, int> oper;

    void postiveTransform(string input, int dir, string& output)
    {
        if (dir == 0)
        {
            char chs[] = { input[3],input[0],input[1],
                           input[6],input[4],input[2],
                           input[7],input[8],input[5] };
            output = string(chs,chs+9);
        }
        else if (dir == 1)
        {
           
            char chs[] = { input[0],input[1],input[2],
                           input[5],input[3],input[4],
                           input[6],input[7],input[8] };
            output = string(chs, chs + 9);
            
        }
    }

    void reverseTransform(string input, int dir, string& output)
    {
        if (dir == 0)
        {
            char chs[] = { input[1],input[2],input[5],
                           input[0],input[4],input[8],
                           input[3],input[6],input[7] };
            output = string(chs, chs + 9);
        }
        else if (dir == 1)
        {

            char chs[] = { input[0],input[1],input[2],
                           input[4],input[5],input[3],
                           input[6],input[7],input[8] };
            output = string(chs, chs + 9);

        }
    }

    void printState(string s)
    {
        printf("%c %c %c\n%c %c %c\n%c %c %c\n\n", s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8]);
    }

    void printRoute(string v)
    {
        vector<string> route = { v };
        string node = v;
        while (node != end)
        {
            postiveTransform(node, (oper[node] & 2)>>1, node);
            route.push_back(node);
        }

        node = v;
        while (node != start)
        {
            reverseTransform(node, (oper[node] & 1), node);
            route.insert(route.begin(), node);
        }
        for (auto s : route)
        {
            printState(s);
        }
    }

public:
    Solution(string st, string en = "012345678")
    {
        start = st;
        end = en;       
    }
    void solve()
    {
        if (start == end)
        {
            cout<<0<<endl;
            printState(start);
            return;
        }

        int ds = 0, de = 0;
        queue<string> ques;
        ques.push(start);
        visitInfo[start] = 1;

        queue<string> quee;
        quee.push(end);
        visitInfo[end] = 2;

        while (!ques.empty() && !quee.empty())
        {
            ds++;
            int cnts = ques.size();
            while (cnts--)
            {
                string node = ques.front(); ques.pop();
                string nbr;
                for (int k = 0; k < 2; k++)
                {
                    postiveTransform(node, k, nbr);
                    {
                        if (!visitInfo.count(nbr))
                        {
                            visitInfo[nbr] = 1;
                            ques.push(nbr);
                            oper[nbr] = k;
                        }
                        if (visitInfo[nbr] == 2)
                        {
                            oper[nbr] |= k;
                            cout << ds + de << endl;
                            printRoute(nbr);
                            return;
                        }

                    }
                }
            }
            de++;
            int cnte = quee.size();

            while (cnte--)
            {
                string node = quee.front(); quee.pop();
                string nbr;
                for (int k = 0; k < 2; k++)
                {
                    reverseTransform(node, k, nbr);
                    {
                        if (!visitInfo.count(nbr))
                        {
                            visitInfo[nbr] = 2;
                            quee.push(nbr);
                            oper[nbr] = k<<1;
                        }
                        if (visitInfo[nbr] == 1)
                        {
                            oper[nbr] |= k<<1;
                            cout << ds + de << endl;
                            printRoute(nbr);
                            return;
                        }

                    }
                }
            }

        }
        cout << "UNSOLVABLE" << endl;;
    }
};

int main()
{
    std::ios::sync_with_stdio(0);
    string st;
    char chs[9];
    for (int i = 0; i < 9; i++)
        cin >> chs[i];
    st = string(chs, chs + 9);
    Solution sol(st);

    sol.solve();
}
