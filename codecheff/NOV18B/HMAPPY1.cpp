#include <iostream>
typedef long long ll;
using namespace std;

ll n, q, k, a[100000], first, second, firstEnd, secondEnd, temp;
bool alwaysK;
string Q;

void findLongestTwo()
{
    ll end = n, j, current;
    first = second = current = 0;
    if (a[n - 1] == 1 && a[0] == 1)
        for (j = n - 1; j >= 0; j--)
        {
            if (a[j] == 1)
            {
                end--;
                current++;
            }
            else
                break;
        }
    for (j = 0; j < end; j++)
    {
        if (a[j] == 0)
        {
            if (current > first)
            {
                second = first;
                first = current;
                secondEnd = firstEnd;
                firstEnd = j - 1;
                // cout << "first and second change to " << first << "  " << second << endl;
            }
            else if (current > second)
            {
                second = current;
                secondEnd = j - 1;
            }
            current = 0;
        }
        else
        {
            current++;
            // cout << current << " c" << endl;
        }
    }
    if (current > first)
    {
        second = first;
        secondEnd = firstEnd;
        first = current;
        firstEnd = end - 1;
    }
    else if (current > second)
    {
        second = current;
        secondEnd = end - 1;
    }
    //check if all are 1
    if (firstEnd == -1)
    {
        firstEnd = n - 1;
        alwaysK = true;
        //little hack
        if(n < k)
            k = n;
    }
    // cout << "first and second are " << first << " " << second << endl;
    // cout << "first end and second end" << firstEnd << " " << secondEnd << endl;
    if ((first >= 2 * k) || (first >= k && second >= k))
        alwaysK = true;
    // cout << "always k " << alwaysK << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> Q;
    alwaysK = false;
    findLongestTwo();
    // if(first > k)
    //     first = k;
    // if(second > k)
    //     second = k;
    if (alwaysK)
    {
        for (int i = 0; i < q; i++)
            if (Q[i] == '?')
                cout << k << endl;
    }
    else
        for (int i = 0; i < q; i++)
        {
            if (Q[i] == '!')
            {
                firstEnd = (firstEnd + 1) % n;
                secondEnd = (secondEnd + 1) % n;
                continue;
            }
            if (firstEnd >= k - 1)
            {
                if (first >= k)
                    cout << k << endl;
                else
                    cout << first << endl;
            }
            else
            {
                temp = max(firstEnd + 1, abs(first - firstEnd - 1));
                temp = min(temp, first);
                // cout << firstEnd + 1 << " in " << abs(first - firstEnd - 1) << endl;
                if (temp > second)
                {
                    if (temp >= k)
                        cout << k << endl;
                    else
                        cout << temp << endl;
                }
                else
                    cout << second << endl;
            }
        }
}