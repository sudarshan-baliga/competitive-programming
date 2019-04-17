#include <iostream>
using namespace std;

int main()
{
    int n, b, a, maxA, cur;
    bool seg[200000];
    cin >> n >> b >> a;
    maxA = a;
    for(int i = 0; i < n; i++)
        cin >> seg[i];
    for(cur = 0; cur < n; cur++)
    {
        if(seg[cur] == 0)
        {
            if(a != 0 && b != 0)
            {
                a -= 1;
                continue;
            }
            else if(b != 0)
                b -= 1;
            else
                break;
        }
        else
        {
            if(b == 1 && a != 0)
            {
               a -= 1;
            }
            else if(b != 0)
            {
                b -= 1;
                a += 1;
                if(a > maxA)
                    a = maxA;
            }
            else if(a != 0 && b != 0)
                a -= 1;
            else
                break;
            
        }
    }
    if(cur => n)
        cout << n << endl;
    else
        cout << cur << endl;
}