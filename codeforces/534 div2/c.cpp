#include <iostream>
using namespace std;

int main()
{
    string s;
    int oneCol = 1, twoCol = 1;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            cout << 1 << " " << oneCol << endl;
            oneCol = (oneCol + 1) % 5;
            if (oneCol == 0)
                oneCol = 1;
        }
        else
        {
            cout << 4 << " " << twoCol << endl;
            if (twoCol == 1)
                twoCol = 3;
            else
                twoCol = 1;
        }
    }
}