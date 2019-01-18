#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[101], cost;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n); 
    cost = 0;
    for(int i = 0; i < n; i+=2)
        cost += a[i + 1] - a[i];
    cout << cost << endl;
}