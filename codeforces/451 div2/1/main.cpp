#include <iostream>

using namespace std;

int main()
{
    long long n,rem,temp;
    cin>>n;
    rem = n%10;

    if(rem <=5)
        {
            n = n/10;
            n = n*10;
            cout<<n;
        }
    else
    {

        temp = 10-rem;
         n = n+temp;
         cout<<n;

    }
}

