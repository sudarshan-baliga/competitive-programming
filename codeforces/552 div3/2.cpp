#include <iostream>
using namespace std;


int main()
{
    int n, a[100], required, cur, i;
    bool success;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(cur = 0; cur <= 100; cur++)
    {
        success = true;
        //subtract first one
        required = a[0] - cur;
        for( i = 1; i < n; i++)
        {
            if(a[i] - cur == required|| a[i] + cur == required || a[i] == required)
                continue;
            success = false;
            break;
        }
        if(success == true)
            break;
        //add to first one
        success = true;
        required = a[0] + cur;
        for(i = 1; i < n; i++)
        {
            if(a[i] - cur == required|| a[i] + cur == required || a[i] == required)
                continue;
            success = false;
            break;
        }
        if(success == true)
            break;
    }
    if(success)
        cout << cur << endl;
    else
        cout << -1 << endl;
}