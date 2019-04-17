#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, freq[27];
    bool began, res, ended;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        memset(freq, 0, 27 * sizeof(int));
        for (char ch : s)
            freq[ch - 97]++;
        began = false;
        ended = false;
        res = true;
        for (int j = 0; j <= 26; j++)
        {
            if (freq[j] > 1)
            {
                res = false;
                break;
            }
            if (freq[j] != 0)
            {
                if (began)
                    continue;
                if (ended)
                {
                    res = false;
                    break;
                }
                began = true;
            }
            else if (began)
            {
                began = false;
                ended = true;
            }
            else if (freq[j] > 0 && !ended)
            {
                began = true;
            }
            else if (freq[j] > 0)
            {
                res = false;
                break;
            }
        }
        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}