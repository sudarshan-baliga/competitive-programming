#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000000
using namespace std;

int getNum(char x)
{
    if (x >= '0' && x <= '9')
        return (int)x - '0';
    else
        return (int)x - 'A' + 10;
}

int getStartBase(string y)
{
    int ans = 0;
    for (auto ch : y)
    {
        ans = max(ans, getNum(ch));
    }
    return max(2, ans + 1);
}

long long convToDecimal(int b, string y)
{
    long long len = y.length(), pow = 1, ans = 0, temp;
    for (int i = len - 1; i >= 0; i--)
    {
        temp = pow * getNum(y[i]);
        if(temp > MAX)
            return -1;
        ans += temp;
        if(ans > MAX)
            return -1;
        pow *= b;
    }
    return ans;
}

void genNumbers(vector<long long> &ans, int b, string y)
{
    long long temp;
    if (b != -1)
    {
        ans.push_back(convToDecimal(b, y));
    }
    else
    {
        int baseInit = getStartBase(y);
        for (int base = baseInit; base <= 36; base++)
        {
            temp = convToDecimal(base, y);
            if (temp == -1)
                break;
            ans.push_back(temp);
        }
    }
}

bool checkCommon(vector<long long> &cur, vector<long long> &prev)
{
    bool found = false;
    vector<long long> common;
    for (int i = 0; i < cur.size(); i++)
        for (int j = 0; j < prev.size(); j++)
        {
            if (cur[i] == prev[j])
            {
                common.push_back(cur[i]);
                found = true;
            }
        }
    prev = common;
    return found;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, b;
    string y;
    vector<pair<int, string>> numbers;
    vector<long long> cur;
    vector<long long> prev;
    bool foundCommon;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> b >> y;
        genNumbers(prev, b, y);
        for (int i = 1; i < n; i++)
        {
            cin >> b >> y;
            numbers.push_back({b, y});
        }
        for (int i = 0; i < n - 1; i++)
        {
            cur.clear();
            genNumbers(cur, numbers[i].first, numbers[i].second);
            foundCommon = checkCommon(cur, prev);
            if (!foundCommon)
                break;
        }
        if (n == 1)
            cout << prev[0] << endl;
        else if (!foundCommon)
            cout << -1 << endl;
        else
            cout << prev[0] << endl;
        numbers.clear();
        prev.clear();
    }
}