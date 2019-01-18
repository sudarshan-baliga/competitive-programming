#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, optimal;
string s;
vector<int> occurance[26];

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> s;
        for (int j = 0; j < n; j++)
            occurance[(int)s[j] - 97].push_back(j);
        //if there is atlest one character then smallest substr is of length 3
        optimal = 3;
        for (int j = 0; j < 26; j++)
        {
            bool found = false;
            for (int k = 0; k < occurance[j].size(); k++)
            {
                for (int l = occurance[j].size() - 1; l >= k + 1; l--)
                    if ((occurance[j][l] - occurance[j][k] + 1) <= (l - k + 1) * 2 + 1)
                    {
                        cout << j << " " << occurance[j][l] << " " << occurance[j][k] << " " << l << " " << k << endl;
                        int subStrLen = (l - k + 1) * 2 + 1;
                        if (subStrLen > optimal)
                            optimal = subStrLen;
                        found = true;
                        break;
                    }
                if (found)
                    break;
            }
        }
        if (optimal > n)
            cout << n << endl;
        else
            cout << optimal << endl;
        for (int j = 0; j < 26; j++)
            occurance[j].clear();
    }
}