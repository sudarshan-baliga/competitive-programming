#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t,p,n,times;
    scanf("%lld",&t);
    for(int i = 0;i< t;i++)
    {
        scanf("%lld%lld",&n,&p);
        if( p == 2 || p == 1)
            printf("impossible");
        else
        {
            times = n/p;
            for(int i = 0 ; i < times; i ++)
             {
                printf("a");
                for(int i = 1; i < p-1 ; i++)
                  printf("b");
                printf("a");
             }
        }
        cout<<endl;


    }
}
