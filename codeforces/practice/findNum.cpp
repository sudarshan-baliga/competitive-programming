// https://codeforces.com/contest/489/problem/C
#include <iostream>
using namespace std;

int main()
{
    int m, s;
    cin >> m >> s;

    if(s == 0 && m > 1)
    {
        cout << -1 << " " << -1;
        return 0;
    }

    if (m == 1 && s == 0)
    {
        cout << "0 "
             << " 0";
        return 0;
    }
    if (s > m * 9)
    {
        cout << "-1"
             << " -1";
        return 0;
    }

    if(m == 1 )
    {
        // cout <<"fd"
        if(s < 10)
            cout << s << " " << s;
        else
            cout << -1 << " " << -1;
        return 0;
    }

    //minimum
    string minima = "";
    int temp = s;
    for (int i = m; i > 0; i--)
    {
        if (s > 9)
        {
            minima = '9' + minima;
            s -= 9;
            continue;
        }
        else
        {
            //check if only 1 is left
            if (i == 1)
            {
                minima = (char)  (s + '0') + minima;
            }
            else
            {
                minima = (char) (s - 1 + '0')+ minima;
                i--;
                while (i != 1)
                {
                    minima = '0' + minima;
                    i--;
                }
                minima = "1" + minima;
                break;
            }
            
        }
    }
    cout << minima << " ";
    //maximum
    s = temp ;
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
            i--;
            while (i != 0)
            {
                cout << "0";
                i--;
            }
            break;
        }
    }
    return 0;
}