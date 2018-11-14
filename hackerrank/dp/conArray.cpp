#include <iostream>
#include <vector>
using namespace std;

int n, k, x;

long long solve()
{
    vector<long long> ending_with_x(n), not_with_x(n);
    ending_with_x[0] = x == 1 ? 1 : 0;
    not_with_x[0] = x == 1 ? 0 : 1;
    for(int i = 1; i < n;i++)
    {
        //all the previous not ending with x will end with x in one of its branches
        ending_with_x[i] = not_with_x[i-1];
        //alll ending with x in previous level will end up with x in current level &
        // all not ending with x in preious level will end up with x when element considered is not x (so k - 2 possibilities)
        not_with_x[i] = (ending_with_x[i-1] * (k-1) + not_with_x[i-1] * (k-2)) % 1000000007;
    }
    return ending_with_x[n-1];
}

int main()
{
    cin >> n >> k >> x;
    cout << solve() << endl;
}