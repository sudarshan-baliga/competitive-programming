#include <iostream>
using namespace std;

int main()
{
    long long a1, b1, a2, b2, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> a1 >> b1 >> a2 >> b2;
        if (a1 != b2)
            cout << a1 << " " << b2 << endl;
        else
            cout << a1 << " " << b2 - 1 << endl;
    }
}