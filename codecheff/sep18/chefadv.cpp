#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t, n, m, x, y;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> x >> y;
        // initially we have knowledge = power  = 1
        n -= 1;
        m -= 1;
        if ( n % x == 0 && m % y == 0){ 
            cout << "Chefirnemo\n";
            continue;
        }
        // else try to use sharechat
        if(n > 0 && m > 0){
        if( (n-1) % x == 0 && (m-1) % y == 0)
          cout << "Chefirnemo\n";
        else
            cout << "Pofik\n";
        }
        else
            cout << "Pofik\n";
    }
}