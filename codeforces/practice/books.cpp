// http://codeforces.com/problemset/problem/279/B
#include<iostream>
using namespace std;

int main() 
{
    long long n, t, b[100000], opti, cur,curCount, optiCount, first;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    optiCount = cur  =  curCount =  0;
    first = 0;
    b[n] = t + 1; //hacker
    for(int i = 0; i <= n; i++)
    {
        cur += b[i];
        if(cur > t)
        {
            if(curCount > optiCount)
                optiCount = curCount;
            cur -= b[first];
            first++;
            continue;
        }
        else
            curCount += 1;      
    }
    cout << optiCount;
}