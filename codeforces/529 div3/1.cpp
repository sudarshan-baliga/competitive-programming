#include <iostream>
using namespace std;

int main()
{
    int n, cur = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i + cur <= n; i += 1)
    {
        cout << s[i + cur];
        cur++;
    }
}