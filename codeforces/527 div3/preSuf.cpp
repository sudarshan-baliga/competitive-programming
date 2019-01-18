#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string temp, max1 = "", max2 = "", original, possible1, possible2;
vector<pair<string, char>> allStr;

bool mark(string x, char order)
{
    for (int i = 0; i < 2 * n - 2; i++)
    {
        if (allStr[i].first == x && allStr[i].second == 'X')
        {
            allStr[i].second = order;
            return true;
        }
    }
    // cout << "not found :" << x << endl;
    //restart the process
    //initialize
    for (int i = 0; i < 2 * n - 2; i++)
    {
        allStr[i].second = 'X';
    }
    return false;
}

int main()
{

    cin >> n;
    for (int i = 0; i < 2 * n - 2; i++)
    {
        cin >> temp;
        allStr.push_back(make_pair(temp, 'X'));
        if (temp.length() > max1.length())
            max1 = temp;
        else if (temp.length() == max1.length())
            max2 = temp;
    }
    int len = max1.length();
    //fuck it check both possible, n is small
    possible1 = max2 + max1[len - 1];
    possible2 = max1 + max2[len - 1];
    // cout << max1.substr(0, len - 1) << " subs " <<  max2.substr(1, len - 1) << endl;
    // cout << original << endl;
    bool res;
    original = possible1;
    for (int i = 0; i < n - 1; i++)
    {
        //i is count. r is for reverse order
        res = mark(original.substr(0, i + 1), 'P');
        if (!res)
        {
            i = -1;
            original = possible2;
            continue;
        }
        res = mark(original.substr(n - i - 1, i + 1), 'S');
        if (!res)
        {
            i = -1;
            original = possible2;
        }
    }
    for (int i = 0; i < 2 * n - 2; i++)
        cout << allStr[i].second;
    cout << endl;
}