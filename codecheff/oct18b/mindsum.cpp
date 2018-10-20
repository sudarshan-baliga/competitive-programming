#include <iostream>
using namespace std;
typedef long long ll;
int digitSum(long long x)
{
    if (x == 0)
        return 0;
    if (x % 9 == 0)
        return 9;
    return x % 9;
}

long long finalDigitSumSteps(long long n, long long d, long long steps)
{
    long long total = n + steps * d, finalSteps = 1, sum = 0;
    //cout << "final total and steps " << total << " " << steps << endl;
    while (total > 0 || sum > 9)
    {
        if (total == 0)
        {
            total = sum;
            sum = 0;
            finalSteps += 1;
        }
       
            sum += total % 10;
            total /= 10;
        
    }
    return finalSteps;
}

ll findUtil(ll n, ll d, ll steps, ll minima)
{
    n = digitSum(n);
    //cout << "n and steps during recursion :" << n << " " << steps << endl;
    if (n == minima)
        return steps;
    return findUtil(n + d, d, steps + 1, minima);
}

void findAnswer(ll n, ll d)
{
    ll minima, steps, finalSteps, tempN = n, tempD = d;
    d = digitSum(d);
    n = digitSum(n + d);
    if ((n == 3 || n == 6 || n == 9) && (d == 3 || d == 6 || d == 9))
        minima = 3;
    else
        minima = 1;
    steps = findUtil(n, d, 1, minima);
    finalSteps = finalDigitSumSteps(tempN, tempD, steps);
    cout << minima << " " << steps + finalSteps << endl;
}

int main()
{
    ll t;
    long long n, d;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        cin >> n >> d;
        if (n == 1)
            cout << 1 << " " << 0 << endl;
        // else if (n + d == 1)
        //     cout << 1 << " " << 1 << endl;
        else
        {
            //cout << " n and d :" << n << " " << d << endl;
            findAnswer(n, d);
        }
    }
}