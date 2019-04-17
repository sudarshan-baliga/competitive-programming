#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main()
{
    int t, n, a[100000], count;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            cin >> a[j];
        sort(a, a + n);
        count = 0;
        for(int j = 0; j < n; j++)
        {
            if(count >= a[j])
                count++;
        }
        cout << count << endl;
    }
}