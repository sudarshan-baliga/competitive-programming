#include <iostream>
#include <cstring>
using namespace std;

int t, n;
long long a, finalCount[32];

void countOnes(long long a)
{
    int bitCount = 0, bit;
    while(bitCount < 32)
    {
        bit = (a) & 1;
        finalCount[bitCount] += bit;
        // cout << bit << " ";
        a = a >> 1;
        bitCount++;
    }
    // cout << endl;
}

long long findAnswer()
{
    long long ans = 0,cur = 1;
    for(int bitCount = 1; bitCount <= 32; bitCount++)
    {
        ans +=  (cur) * min(finalCount[bitCount - 1], n - finalCount[bitCount - 1]);
        cur *= 2;
    }
    return ans;
}


int main() {
   cin >> t;
   for(int i = 0; i < t; i++)
   {
       cin >> n;
       for(int j = 0; j < n; j++)
       {
           cin >> a;
           countOnes(a);
       }
       cout << findAnswer() << endl;
       memset(finalCount, 0, 32 * sizeof(long long));
   }
}