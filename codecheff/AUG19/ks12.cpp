#include <iostream>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

void updateOnes(int ones[][33], int idx, int val)
{
    bitset<32> b(val);
    string bitStr = b.to_string();
    reverse(bitStr.begin(), bitStr.end());
    cout << bitStr << endl;
    for (int i = 1; i <= 32; i++)
    {
        ones[idx][i] = (bitStr[i - 1] == '1' ? 1 : 0);
    }
}

void updateLeftRight(int ones[][33], pair<int, int> leftRight[][33], int idx, bool isLeft)
{
    for (int i = 1; i <= 33; i++)
    {
        if (ones[idx][i])
        {
            if (isLeft)
            {
                leftRight[idx][i].second = leftRight[idx - 1][i].first + 1;
                leftRight[idx][i].first = leftRight[idx - 1][i].second;
            }
            else
            {
                leftRight[idx][i].second = leftRight[idx + 1][i].first + 1;
                leftRight[idx][i].first = leftRight[idx + 1][i].second;
            }
        }
        else
        {
            if (isLeft)
            {
                leftRight[idx][i].first = 1 + leftRight[idx - 1][i].first;
                leftRight[idx][i].second = leftRight[idx - 1][i].second;
            }
            else
            {
                leftRight[idx][i].first = 1 + leftRight[idx + 1][i].first;
                leftRight[idx][i].second = leftRight[idx + 1][i].second;
            }
        }
    }
}

int main()
{
    int t, n, a, ones[1002][33];
    long long ans, temp;
    pair<int, int> left[1002][33], right[1002][33];
    bool valid;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            updateOnes(ones, i, a);
        }
        left[0][0].first = 0;
        left[0][0].second = 0;
        right[n + 1][0].first = 0;
        right[n + 1][0].second = 0;
        for (int i = 1; i <= n; i++)
        {
            updateLeftRight(ones, left, i, true);
        }
        for (int i = n; i > -1; i--)
            updateLeftRight(ones, right, i, false);
        for (int j = 1; j <= 6; j++)
        {
            for (int i = 1; i <= n; i++)
                cout << left[i][j].first << " " << left[i][j].second << ", ";
            cout << endl;
        }
        ans = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            temp = 1;
            for (int j = 1; j <= 5; j++)
            {
                temp *=
                    (left[i][j].first * right[i + 1][j].first) +
                    (left[i][j].second * right[i + 1][j].second);
                    cout << temp << endl;
            }
            ans += temp;
        }
        cout << ans << endl;
    }
}
