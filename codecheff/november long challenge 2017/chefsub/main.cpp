#include <bits/stdc++.h>
long long n,q,l,r,count1 = 0, zero,temp,type,xl,yr;
bool a[1000000];
bool find1(long long x,long long l,long long r)
{
    for(int i =r-1;i >= l; i++)
    {
        if(a[i]==x)
            return 1;
    }
    return 0;
}

using namespace std;

int main()
{
    scanf("%lld%lld%lld%lld",&n,&q,&l,&r);
    for(int i =0;i < q;i++)
    {
        scanf("%lld%lld%lld",&type,&xl,&yr);
        if(type == 1)
        {
            if(yr > l && yr < r)
              {
                  a[xl] = yr;
              }
              else
                a[xl]=0;

        }
        else
        {
            count1 = 0;
            temp = 0;
            for(int j = xl; j<= yr;j++)
            {
                if(a[j]!=0)
                {
                    count1++;
                }
            }
             zero = yr-xl - count1+1;
             cout<<count1<<zero<<endl;

                for(int j = 1; j<count1;j++)
                    temp = temp+(--count1);
                if(zero > 0)
                    count1 *= 2;
                count1 += temp;
                printf("%lld",count1);

        }
    }

}
