#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a[1001], pre, current = 0, preMax = 0, startMax = 0, endMax = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //find consequtive
    pre = a[1];
    //check for end condition
    if (1000 - a[1] == n - 1)
    {
        if (endMax < n - 1)
            endMax = n - 1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (a[i] - pre == 1)
        {
            if (current == 0)
                current = 1;
            current++;
            pre = a[i];
        }
        else
        {
            if ((current - 2) > preMax && current > 2)
            {
                // cout << a[i] << current << endl;
                preMax = current - 2;
            }
            pre = a[i];
            current = 0;
        }
        if (a[i] == i)
            if (startMax < i - 1)
                startMax = i - 1;
        if (1000 - a[i] == n - i)
        {
            if (endMax < n - i)
                endMax = n - i;
        }
    }
    //check if it last part of array is consecutive
    if (current > preMax && current > 2)
    {
        preMax = current - 2;
        current = 1;
    }
    // cout << preMax << " " << startMax << " " << endMax << endl;
    preMax = max(preMax, startMax);
    cout << max(preMax, endMax);
}