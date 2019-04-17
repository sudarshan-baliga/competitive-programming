#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[200000];
    vector<int> v1, v2;
    bool failed;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    failed = false;
    v1.push_back(a[0]);
    if (n != 1)
    {
        v2.push_back(a[1]);
    }
    for (int i = 2; i < n; i++)
    {
        if (a[i] == v1.back())
        {
            if (a[i] == v2.back())
            {
                failed = true;
                break;
            }
            v2.push_back(a[i]);
        }
        else
            v1.push_back(a[i]);
    }
    if (failed)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << v1.size() << endl;
        for (int ele : v1)
            cout << ele << " ";
        cout << endl;
        cout << v2.size() << endl;
        for (auto itr = v2.rbegin(); itr != v2.rend(); itr++)
            cout << *itr << " ";
        cout << endl;
    }
}