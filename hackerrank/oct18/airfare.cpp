#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int p, s, t, h, x;
    ll cost = 0;
    cin >> p >> s >> t >> h >> x;
    if (s - x > t)
        cost = p * x;
    else
    {
        if (s > t)
        {
            cost = p * (s - t);
            x -= s - t;
        }
        cost += x * h;
    }
    cout << cost;
}