#include <bits/stdc++.h>

using namespace std;
long long t,prevnum,prevans;
struct numbers
{
    long long val,pos,ans;
}s[1000000];
bool sortstruct1(struct numbers x, struct numbers y)
{
    if(x.val > y.val)
        return 0;
    else
        return 1;
}
bool sortstruct2(struct numbers x, struct numbers y)
{
    if(x.pos > y.pos)
        return 0;
    else
        return 1;
}
long long calculate(long long x)
{
    long long rem,oddtemp,eventemp;
    rem = 0;oddtemp = 0;eventemp = 0;
    while(x!=0)
    {
      rem = x % 10;
      x = x / 10;
      if(rem % 2 == 0)
       eventemp += rem;
      else
        oddtemp += rem;
    }
    return abs(eventemp-oddtemp);
}

long long  ans(long long n)
{
    long long b,total = 0,limit;
    if(prevnum == n)
    {
        return prevans;
    }
    else
        total = prevans;
    b = prevnum + 1;
    limit = b+prevnum;
    while(b!=n+1)
    {
        for(int i = b; i < limit; i++)
           {
            total += 2*calculate(i+1);

           }
           total += calculate(limit+1);

           b++;
    }
    prevnum = --b;
    prevans = total;
    return total;
}

int main()
{
    scanf("%lld",&t);
    for(int i = 0; i < t; i++)
    {
     scanf("%lld",&s[i].val);
     s[i].pos = i;

    }
    sort(s,s+t,sortstruct1);
    prevnum = 1;
    prevans = 2;
    for(int i =0; i < t; i++)
    {
      s[i].ans = ans(s[i].val);
    }

    sort(s,s+t,sortstruct2);
    for(int i =0; i < t; i++)
    {
      printf("%lld\n",s[i].ans);
    }
}
