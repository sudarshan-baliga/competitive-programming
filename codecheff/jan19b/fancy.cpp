#include <iostream>
#include <string>
using namespace std;

bool findnot(string s)
{
    string str;
    for (auto ch : s)
    {
        if (ch == ' ')
        {
            if (str == "not")
                return true;
            else
                str = "";
            continue;
        }
        str += ch;
    }
    if(str == "not")
        return true;
    return false;
}

int main()
{
    int t;
    string s;
    cin >> t;
    getline(cin, s);
    for (int i = 0; i < t; i++)
    {
        getline(cin, s);
        if(findnot(s))
            cout << "Real Fancy\n";
        else
            cout << "regularly fancy\n";
    }
}