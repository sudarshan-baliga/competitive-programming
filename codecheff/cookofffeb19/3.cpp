#include <iostream>
#include <string.h>
#include <set>
using namespace std;

int main()
{
    int t, n, curSize, prevSize;
    string s, bestPref;
    bool failed;
    set<int> bestIdx;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> s;
        // get all the possible places
        bestIdx.clear();
        for (int j = 1; j < n; j++)
        {
            if (s[0] == s[j])
                bestIdx.insert(j);
        }
        if (bestIdx.size() == 0)
        {
            cout << s << endl;
            continue;
        }
        curSize = 2;
        while (true)
        {
            failed = false;
            for (int idx : bestIdx)
            {
                // cout << curSize << " " << idx << endl;
                if (idx + curSize > n || s.substr(idx, curSize) != s.substr(0, curSize))
                {
                    failed = true;
                    break;
                }
            }
            if (failed)
            {
                bestPref = s.substr(0, curSize - 1);
                break;
            }
            curSize++;
        }
        cout << bestPref << endl;
    }
}