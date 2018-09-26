#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long n,r,ary[100000],right,left,prev;
   int t;
   bool flag;  //direction
   scanf("%d",&t);

   for(int i =0;i < t;i++)
   {
       flag = 0;
       scanf("%lld %lld",&n,&r);
       for(int temp = 0;temp < n;temp++)
        scanf("%lld",&ary[temp]);
       prev = ary[0];
       right = left = -1;
       for(int j = 1;j < n;j++)
       {
           if(ary[j] < left && left!= -1)
           {
               flag =1;
               break;
           }
           if(ary[j] > right && right != -1)
           {
               flag = 1;
               break;
           }
           if(ary[j] < prev ) right = prev;
           else left = prev;
           prev = ary[j];
       }
       if(flag)
        printf("NO\n");
       else
        printf("YES\n");
   }

  return 0;
}
