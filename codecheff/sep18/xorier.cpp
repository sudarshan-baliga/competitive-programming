// all even numbers can be represented as sum of two odd numbers exce-
//-pt 4 ( but can be represe as 2 + 2 sum of two even prime numbers)
// no odd numbers can be represented as sum of two even or two odd prime numbers
// we also want xors not to be 0 or 2(xor of equal numbers and a ^ b = 2 case)
#include <iostream>
#include <string.h>
using namespace std;
long long t, n, a[100000], noOfOdd, noOfEven, occurence[1000002], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        noOfOdd = 0;
        noOfEven = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (a[j] & 1)
                noOfOdd++;
            else
                noOfEven++;
            occurence[a[j]] += 1;
        }
        // add no of ways of selecting pairs of even and odd to ans (n * (n -1) / 2 formula for selecting pairs)
        ans = (noOfOdd * (noOfOdd - 1)) / 2;
        ans += (noOfEven * (noOfEven - 1)) / 2;
        // cout << ans << "ans" << endl;
        // remove all the cases where 2 numbers are equal (i.e. xor is 0) and two numbers Xor is 2
        for (int j = 0; j < n; j++)BSHUFFLE
        {
            occurence[a[j]]--;
            // remove equal pairs
            if (occurence[a[j]] > 0)
                ans -= occurence[a[j]];
            // remove pairs where xor is 2
            if (occurence[(a[j] ^ 2)] > 0 && (a[j] ^ 2) <= 1000000)
                ans -= occurence[(a[j] ^ 2)];
            // cout << a[j] << " " <<  ans << endl;
        }
        cout << ans << endl;
        memset(occurence, 0, 1000002 * sizeof(occurence[0]));
    }
}