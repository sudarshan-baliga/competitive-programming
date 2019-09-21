#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool revsort(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

int main()
{
    int n, a, x;
    vector<pair<int, int>> cans;
    vector<int> seq;
    long long ans;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        cans.push_back({a, i}); 
    }
    sort(cans.begin(), cans.end(), revsort);
    ans = 0;
    x = 0;
    for(auto can: cans)
    {
        ans += (can.first * x) + 1;
        seq.push_back(can.second);
        x++;
    }
    cout << ans << endl;
    for(auto ele : seq)
        cout << ele + 1 << " ";
    cout << endl;

}