#include <iostream>
typedef long long ll;
using namespace std;

int main()
{
    ll t, n, b, w, h, p, bestArea, curArea;
    bool found;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> b;
        found = false;
        bestArea = -1;
        for(int j = 0; j < n; j++)
        {
            cin >> w >> h >> p;
            if(p <= b)
            {
                found = true;
                curArea = w * h;
                if(curArea > bestArea)
                    bestArea = curArea;
            }
        }
        if(found)
            cout << bestArea << endl;
        else
            cout << "no tablet" << endl;
    }
}