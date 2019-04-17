#include <iostream>
using namespace std;


int main()
{
    long long n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 0; i< n; i++)
    {
        if(s[i] % 2 == 0 )
            ans += i + 1;
    }
    cout << ans <<endl;
}