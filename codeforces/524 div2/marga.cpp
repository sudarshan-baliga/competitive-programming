#include <iostream>
#include <cmath>
using namespace std;

long long q, lsum, rsum, ans;
float l, r, temp;
// long long prefix[1000000001], n = 1000000001,
// void preprocess()
// {
//     long long temp;
//     for (long long i = 1; i <= 10; i++)
//     {
//         prefix[i] = prefix[i - 1];
//         if (i % 2)
//            temp = i * -1;
//         else
//             temp = i;
//         prefix[i] += temp;
//     }
// }

long long calculate(float x)
{
    long long sum = 0, temp;
    temp = x;
    x = floor(x / 2);
    sum = x * (x + 1);
    x = temp;
    x = ceil(x / 2);
    sum -= pow(x, 2);
    return sum;
}

int main()
{
    // preprocess();
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        ans = calculate(r) - calculate(l);
        (int)l % 2 ? temp = -1 *l : temp = l;
        if (l != r)
            cout << ans + temp  << endl;
        else
            cout << temp << endl;
        // cout << calculate(l) <<  " "  << calculate(r) << endl ;
    }
}