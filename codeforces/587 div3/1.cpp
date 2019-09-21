#include <iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 1; i <= n; i += 2)
    {
        if((s[i] == 'a' && s[i - 1] == 'b') || (s[i] == 'b' && s[i - 1] =='a'))
            continue;
        if(s[i] == 'a')
            s[i] = 'b';
        else 
            s[i] = 'a';
        ans++;
    }
    cout << ans <<endl;
    cout << s << endl;
}