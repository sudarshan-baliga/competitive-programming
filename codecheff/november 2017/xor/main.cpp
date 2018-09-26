#include <iostream>

using namespace std;
long long n,q,a[1000000],typ,x,k,temp,pre,count,xors[1000000];

void xorfun(long long b,long long e)
{
    for(int i = b; i <= e; i++)
        xors[i] = xors[i] ^ xors[i-1];
}

int main()
{
    cin>>n>>q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1 ; i <= n; i++)
        xors[i] = a[i] ^ xors[i-1];

    for(int i = 0; i < q; i++)
    {
        cin>>typ>>x>>k;
        if(typ == 2)
        {
            count = 0;
            for(int j = 1; j <=x ; j++)
                if(xors[j] == k)
                   count++;
            cout<<count<<endl;
        }
        if(typ == 1)
         {
             xors[x] = k;
             xorfun(x,n);
         }

    }
}
