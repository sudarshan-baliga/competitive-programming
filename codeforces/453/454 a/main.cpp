#include <iostream>

using namespace std;

int main()
{
    long long v1,v2,v3,v4,flag = 1,a1,a2,a3;
    cin>>v1>>v2>>v3>>v4;
    {
        if(2*v1 > 2*v4)
            a1 = 2*v1;
        else
            flag = 0;
        if(2*v2 > 2*v4)
            a2 = 2*v2;
        else
            flag = 0;
        if(2*v1 > 2*v4)
            a3 = 2*v3;
        else
            flag = 0;

    }


    if(flag == 1)
    {
        cout<<a1<<" "<<a2<<" "<<a3;
    }
    else
        cout<<-1;
}
