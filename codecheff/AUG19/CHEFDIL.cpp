#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, l;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l = s.length();
        for(int i = 0; i < l - 1; i++)
        {
            if(s[i] == '1')
            {
                if(s[i + 1] == '1')
                    s[i + 1] = '0';
                else
                    s[i + 1] = '1';
            }
        }
        if(s[l - 1] == '1')
            cout << "WIN" << endl;
        else 
            cout << "LOSE" << endl;
    }
}