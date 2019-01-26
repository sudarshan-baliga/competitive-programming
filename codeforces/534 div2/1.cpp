#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int idx = 0, count = 0;
    cin >> s;
    while (idx != s.length())
    {
        if (idx + 1 < s.length() && s[idx] == s[idx + 1])
        {
            s.erase(idx, 2);
            count++;
            if ( (idx - 1) >= 0)
            {
                idx--;
                continue;
            }
        }
        else
            idx++;
    }
    if(count % 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}