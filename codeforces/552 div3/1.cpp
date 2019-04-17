#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    long long a, b, c, d, sum, id = 0;
    cin >> a >> b >> c >> d;
    sum = max({a, b, c, d});
    if(a != sum)
        cout << sum -a << " ";
    if(b != sum)
        cout << sum - b << " ";
    if(c != sum)
        cout << sum - c << " ";
    if(d != sum)
        cout << sum - d << " ";
    cout << endl;
 }