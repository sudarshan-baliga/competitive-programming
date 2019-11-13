#include <iostream>
#include <vector>
#include <map>
#define  ll long long
using namespace std;

int main()
{
    ll n,q, x, y, bact[500001], v, k;
    char ch;
    cin >> n >> q;
    vector<ll> edges[n + 1];
    for(int i = 1; i < n; i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
    }
    for(int i = 1; i<= n; i++)
    {
        cin >> bact[i];
    }
    while(q--)
    {
        cin >> ch;
        if(ch == '+')
        {
            cin >> v >> k;
        }
        else {
            cin >> v;
        }
    }

}