// https://codeforces.com/problemset/problem/545/C
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, x[100002], h[100002], stay, left, right;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> h[i];
    stay = left = right = h[0] = h[n + 1] = 0;
    x[0] = INT32_MIN;
    x[n + 1] = INT32_MAX;
    for (int i = 1; i <= n; i++)
    {
        long long tempLeft = left, tempRight = right, tempStay = stay;
        //make it stay
        //if u could make the previous tree fall to right
        if (h[i - 1] + x[i - 1] < x[i])
            tempStay = max({right, stay, left});
        else
            tempStay = max(left, stay);

        //make it fall left
        //if pre tree has fallen right and if it is
        //  possible to make the current tree fall left
        if (x[i] - h[i] > x[i - 1] + h[i - 1])
            tempLeft = max({right, left, stay}) + 1;
        else if (x[i] - h[i] > x[i - 1])
            tempLeft = max(left, stay) + 1;
        //make it fall right
        if (x[i] + h[i] < x[i + 1])
        {
            if (x[i - 1] + h[i - 1] < x[i])
                tempRight = max({left, right, stay}) + 1;
            else
                tempRight = max({left, stay}) + 1;
        }
        left = tempLeft, right = tempRight, stay = tempStay;
        // cout << i << " " << left << " " << stay << " " << right << endl;
    }
    cout << max({left, right, stay});
}