//fuck it i have lost the control over it
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int t, n, a[2002], freq[2002];
long long c[1005][1005], ans;
map<multiset<int>, bool> visited;

bool findMedian(multiset<int> x)
{
    auto itr = x.begin();
    int size = x.size();
    advance(itr, size / 2);
    auto itr2 = itr--;
    return *itr == *itr2;
}

void dupSub(multiset<int> current, int left, int right, bool considered)
{

    if (!considered && visited.find(current) != visited.end())
    {
        considered = true;
        if (current.size() % 2)
        {
            visited.insert(make_pair(current, true));
            ans++;
        }
        else
        {
            bool median = findMedian(current);
            // cout << "Median in current  iteration " << index << " " << median << endl;
            if (median)
            {
                visited.insert(make_pair(current, true));
                ans++;
            }
        }
    }

    if (left - 1 < 0 && right + 1 > n)
        return;
    //do not consider left and right
    dupSub(current, left - 1, right + 1, true);
    // consider and do not consider left
    if (left > 0)
    {
        multiset<int> temp = current;
        temp.insert(a[left - 1]);
        dupSub(temp, left - 1, right + 1, false);
    }
    // consider and do not consider right
    if (left < n)
    {
        multiset<int> temp = current;
        temp.insert(a[right + 1]);
        dupSub(temp, left, right + 1, false);
    }

    //consider both left and right
}

void repetition(int start, int count)
{
    //generate the different combination of repetition
    // https://www.geeksforgeeks.org/subarraysubstring-vs-subsequence-and-programs-to-generate-them/
    long long size = pow(2, count) - 1;
    int currentStart, end;
    bool gotStart = false;
    multiset<int> temp;
    for (int counter = 1; counter <= size; counter++)
    {
        temp.clear();
        for (int j = 0; j < 32; j++)
        {
            if (counter & 1 << j)
            {
                if (!gotStart)
                    currentStart = end = start + j;
                else
                    end = start + j;
                temp.insert(a[start]);
            }
        }
        dupSub(temp, currentStart, end, false);
    }
    // //for handling some repetitions (ex when str = 1111 then 111 is considered in while considering single one and all3 1s)
    // for (int k = 3; k <= count; k++)
    //     ans = (ans - c[count][k]);
    freq[a[start]] = 0;
}

//find the combination
void combi(int n, int r)
{
    for (int i = 0; i <= n; i++)
    {
        // C(i,0) = 1 for i = 0...n
        c[i][0] = 1;
    }

    for (int j = 0; j <= r; j++)
    {
        // if n = 0, C(n,r) = 0 for all 'r'
        c[0][j] = 1; //actually 0
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if (i == j)
            {
                // C(n,n) = 1
                c[i][j] = 1;
            }
            else if (j > i)
            {
                // case when r > n in C(n,r)
                c[i][j] = 0;
            }
            else
            {
                // apply the standard recursive formula
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    combi(1001, 1001);
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        ans = 0;
        fill_n(freq, n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            cin >> a[j];
            freq[a[j]] += 1;
        }
        for (int j = 1; j <= n; j++)
        {
            // cout << j << "bb " << endl;
            if (freq[a[j]] > 1)
                repetition(j, freq[a[j]]);
            else if (freq[a[j]] == 1)
                for (int k = 0; k <= min(j - 1, n - j); k++)
                {
                    // cout << "j and k " << j << " " << k <<  " " << (c[j - 1][k]) << " r & l " << c[n - j][k]  << " ";
                    ans = (ans + (c[j - 1][k]) * c[n - j][k]) % 1000000007;
                }
            // cout << endl;
        }
        cout << ans << endl;
    }
}