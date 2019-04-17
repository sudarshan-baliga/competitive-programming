#include <iostream>
using namespace std;

int main()
{
    int n, a, b, max1, max2;
    cin >> n;
    cin >> a >> b;
    max1 = max(a, b);
    max2 = min(a, b);
    for(int i = 2; i < n; i++)
    {
        cin >> a;
        if(a > max1)
        {
            max2 = max1;
            max1 = a;
            continue;
        }
        if(a > max2 && a != max1)
            max2 = a;
    }
    cout << max2 % max1 << endl;
}   