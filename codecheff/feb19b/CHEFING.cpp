#include <iostream>
using namespace std;

int main()
{
    int t, n, alpha[26], count;
    string s;
    bool visited[26];
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        fill_n(alpha, 26, 0);
        for(int j  = 0; j < n; j++)
        {
            cin >> s;
            fill_n(visited, 26, false);
            for(char ch : s)
            {
                if(visited[ch  - 97] == false)
                {
                    visited[ch - 97] = true;
                    alpha[ch - 97]++;
                }
            }
        }
        count = 0;
        for(int ele: alpha)
            if(ele == n)
            {
                count++;
            }
        cout << count << endl;
    }
}