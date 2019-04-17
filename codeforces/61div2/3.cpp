#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int n, q, l, r, rangeCount[50001], paintersRequired = 0;

unordered_set<int> included;

bool minimumColorCount(unordered_set<int> a, unordered_set<int> b)
{
    return a.size() < b.size();
}

int main()
{
    cin >> n >> q,;
    vector<unordered_set<int>> fence(n);
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        rangeCount[i] = r - l + 1;
        for (int j = l; j <= r; j++)
            fence[j - 1].insert(i);
    }
    sort(fence.begin(), fence.end(), minimumColorCount);
    for (auto section : fence)
    {
        for (auto color : section)
        {
            cout << color << " ";
        }
        cout << endl;
    }

    for (auto section : fence)
    {
        bool colored = false;
        for (auto color : included)
        {
            if (section.find(color) != section.end())
            {
                colored = true;
                cout << "already colored " << color << endl;
                break;
            }
        }
        if (!colored)
        {
            // else find color with max count
            int max = -1, maxColor = -1;
            for (auto color : section)
                if (rangeCount[color] > max)
                {
                    max = rangeCount[color];
                    maxColor = color;
                }
            cout << maxColor << endl;
            included.insert(maxColor);
            paintersRequired++;
        }
    }
    // if(paintersRequired < q -)
    cout << paintersRequired << endl;
}