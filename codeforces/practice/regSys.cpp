// https://codeforces.com/problemset/problem/4/C
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    string s;
    map<string, int> db;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        auto pos = db.find(s);
        if ( pos == db.end())
        {
            db.insert(make_pair(s, 0));
            cout << "OK" << endl;
        }
        else
        {
            db[s] += 1;
            cout << s  << db[s] <<  endl;
        }
    }
}