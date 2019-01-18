#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    long long minimaA, maximaB, temp, minIdxA, maxIdxB;
    cin >> n >> m;
    cin >> minimaA;
    minIdxA = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        if (temp < minimaA)
        {
            minimaA = temp;
            minIdxA = i;
        }
    }
    cin >> maximaB;
    maxIdxB = 0;
    for (int i = 1; i < m; i++)
    {
        cin >> temp;
        if (temp > maximaB)
        {
            maximaB = temp;
            maxIdxB = i;
        }
    }
    for (int i = 0; i < m; i++)
        cout << minIdxA << " " << i << endl;
    for (int i = 0; i < n; i++)
    {
        if(i != minIdxA)
            cout << i << " " << maxIdxB << endl;
    }
}