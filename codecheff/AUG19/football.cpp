#include <iostream>
using namespace std;

int main() 
{
    int t, n, a[150], b, maxi;
    cin >> t;
    while(t--)
    {
        cin >> n;
        maxi = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
        {
            cin >> b;
            maxi = max(20 * a[i] - b * 10, maxi);
        }
        cout << maxi << endl;
    }
}