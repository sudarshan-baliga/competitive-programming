#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t, n, occur[1000001], temp, eleCount, sameEleCount;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if (occur[temp] == 0)
                a.push_back(temp);
            occur[temp]++;
        }
        eleCount = sameEleCount = 0;
        for (auto ele = a.begin(); ele < a.end(); ele++)
        {
            for (auto ele2 = a.begin(); ele2 < a.end(); ele2++)
            {
                if (occur[*ele] >= *ele2 && occur[*ele2] >= *ele)
                    eleCount++;
            }
            // cout << *ele << " " <<eleCount <<  endl;
        }
        a.clear();
        fill_n(occur, 1000001, 0);
        cout << eleCount << endl;
    }
}