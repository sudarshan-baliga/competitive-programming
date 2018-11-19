#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k, a[200001], freq[200001];
vector<pair<int, int>> eleFreq;

bool check(int x)
{
    int count = 0;
    for (int i = 0; i <= eleFreq.size(); i++)
        count += eleFreq[i].first / x;
    if (count >= k)
        return true;
    return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    for (int i = 0; i < 200001; i++)
    {
        if (freq[i] != 0)
            eleFreq.push_back(make_pair(freq[i], i));
    }
    sort(eleFreq.begin(), eleFreq.end(), greater<>());
    int b = 0, e = n - 1, m, best = 0;
    while (b <= e)
    {
        m = (b + e) / 2;
        if (check(m))
        {
            best = m;
            b = m + 1;
        }
        else
            e = m - 1;
    }
    int count = 0, current = 0, curIdx = 0;
    while(count != k)
    {
       current = eleFreq[curIdx].first / best; 
       while(count != k && current != 0)
       {
           cout << eleFreq[curIdx].second << " ";
           count++;
           current--;
       } 
       curIdx++;
    }
}
