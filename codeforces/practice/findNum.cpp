// https://codeforces.com/contest/489/problem/C
#include <iostream>
using namespace std;

int main()
{
    int m, s;
    cin >> m >> s;
    if (m == 1 && s == 0)
    {
        cout << "0 " << " 0";
        return 0;
    }
    if (s > m * 9)
    {
        cout << "-1"
             << " -1";
        return 0;
    }
    //maximum
    for (int i = m; i > 0; i--)
    {
        if (s > 9)
        {
            cout << "9";
            s -= 9;
            continue;
        }
        else
        {
            cout << s;
            break;
        }
    }
}