#include <bits/stdc++.h>
long long ary[101];
using namespace std;

int main()
{
    long long n,b,temp1,temp2;
    cin>>n>>b;
    for(int i = 0 ; i < n; i++)
    {
        cin>>temp1>>temp2;
        for(int j = temp1;j <= temp2 ; j++)
            ary[j] = 1;

    }
    for(int i = 0; i <= b ;i++)
    {
        if(ary[i] != 1)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
