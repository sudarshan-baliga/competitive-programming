#include <iostream>
using namespace std;

int main()
{
    int t, x, y, z;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y >> z;
        if( (x + y == z) || (x + z  == y) || (y + z ==  x))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}