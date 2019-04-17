#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, sum, oddMax = -1, evenMax = -1;
vector<int> even, odd;

int removeEle()
{

    while (odd.size() != 0 && even.size() != 0)
    {
        sum -= odd.back();
        sum -= even.back();
        odd.pop_back();
        even.pop_back();
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a % 2)
        {
            odd.push_back(a);
        }
        else
        {
            even.push_back(a);
        }
        sum += a;
    }
    if (odd.size() == even.size())
    {
        cout << 0 << endl;
        return 0;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    if (odd.size() > even.size())
    {
        sum -= odd.back();
        odd.pop_back();
    }
    else
    {
        sum -= even.back();
        even.pop_back();
    }
    cout << removeEle() << endl;
}