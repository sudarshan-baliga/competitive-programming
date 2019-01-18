// https://codeforces.com/problemset/problem/277/A
#include <iostream>
#include <vector>
using namespace std;

int n, m, count, temp, cost;
int langs[101][101];
vector<int> empCon[101];
bool atLeatOne, included[101];

void dfs(int i)
{
    included[i] = true;
    for (auto ele : empCon[i])
        if (!included[ele])
        {
            // cout  << ele << " " << i;
            dfs(ele);
        }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> count;
        if (count > 0)
            atLeatOne = true;
        for (int j = 1; j <= count; j++)
        {
            cin >> temp;
            langs[i][temp] = 1;
        }
    }

    //if no one knows any language
    //teach everyone any one common language
    if (!atLeatOne)
    {
        cout << n << endl;
        return 0;
    }
    //find the emplooyee connection
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                if (langs[i][k] && langs[j][k])
                {
                    empCon[i].push_back(j);
                    empCon[j].push_back(i);
                    // cout << i << " " << j << endl;
                    break;
                }
    //find how many dissconnected components are there
    for (int i = 1; i <= n; i++)
        if (!included[i])
        {
            cost++;
            dfs(i);
        }
    cout << cost - 1 << endl;
}