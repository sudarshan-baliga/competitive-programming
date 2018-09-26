#include <iostream>
using namespace std;

int main()
{
    long long t, n, z1, z2, a[50];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> z1 >> z2;
        for (int j = 0; j < n; j++)
            cin >> a[j];
        // lets try to pass the first test case
        if (abs(a[0]) == z1 || abs(a[0]) == z2 || abs(a[1]) == z1 || abs(a[1]) == z2)
            cout << 1 << endl;
        else if ((abs(a[0]) == abs(a[1])) && (z1 == 0 || z2 == 0))
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
}