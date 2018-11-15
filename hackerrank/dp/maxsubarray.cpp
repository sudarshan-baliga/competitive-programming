#include <iostream>
using namespace std;

long long t, n, a[100000], subarray, subsequence, maxima;

long long findSubarraySum()
{
    long long cur = 0, maxima = 0;
    for (int j = 0; j < n; j++)
    {
        cur += a[j];
        if (cur > maxima)
            maxima = cur;
        if(cur < 0)
            cur = 0;
    }
    return maxima;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        maxima = -10001;
        subsequence = subarray = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (a[j] > maxima)
                maxima = a[j];
            if (a[j] > 0)
                subsequence += a[j];
        }
        subarray =  findSubarraySum();
        if(subsequence == 0)
            subsequence = maxima;
        if(subarray == 0)
            subarray = maxima;
        cout << subarray << " " << subsequence << endl;
    }
}