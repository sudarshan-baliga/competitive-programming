#include<iostream>
typedef long long ll;
using namespace std;

int main() 
{
    int x, a;
    cin >> x;
    if(x == 1)
    {
        cout << -1;
        return 0;
    }   
    a = 2;
    while(x % 2)
        x -= 1;
    cout << x << " "  << a; 

}   