#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    ll n, root = 0, mul = 0, ansRoot = 0, curr;
    bool found = false;
    cin >> n;
    while (true)
    {
        found = false;
        for (int i = 1; i < n; i++)
        {
            curr = n * i;
            root = sqrt(curr);
            if (root * root == curr)
            {
                found = true;
                if (i != 1)
                    mul++;
                ansRoot++;
                n = root;
                // cout << found << " root " << root << endl;
                break;
            }
        }
        if (found)
            continue;
        break;
    }
    if(mul)
        ansRoot++;
    cout <<n << " " <<  ansRoot;
}