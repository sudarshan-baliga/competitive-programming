#include <iostream>
using namespace std;

int main()
{
    int t, n, a, b, c, temp, arr[20];
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> a >> b;
        if(a > b)
        {
            temp = b;
            b = a;
            a = b;
        }
        arr[0] = a;
        arr[1] = b;
        for(int i = 2;i < n; i++)
        {
            cin >> c;
            if(c >= b)
            {
               b = c;
            }
            if(c <= a)
            {
                a = b;
                b = c;
            }
        }
        cout << a << " " << b << endl;
    }
}