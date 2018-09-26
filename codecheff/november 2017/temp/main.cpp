#include <iostream>
long long fact( long long x){ if(x == 1) return 1; else return x*fact(x-1);}

using namespace std;

int main()
{
    cout<<fact(10);
    return 0;
}
