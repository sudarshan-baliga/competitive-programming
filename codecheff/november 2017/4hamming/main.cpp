    #include <bits/stdc++.h>

    using namespace std;
    long long t,n,a[100000];
    int main()
    {
      scanf("%lld",&t);
      for(int i = 0;i < t;i++)
      {
          scanf("%lld",&n);
          for(int j = 0;j < n ;j++)
            scanf("%lld",&a[j]);
         if(n !=2 && n != 3)
          {
              if(n == 1)
                printf("0\n");
              else
              printf("%lld\n",n);
              for(int j = n/2; j <n;j++)
                printf("%lld ",a[j]);
              for(int j = 0; j <n/2;j++)
                printf("%lld ",a[j]);
              printf("\n");
          }
         else
         if(n == 2)
           {
              if(a[0] == a[1])
                printf("0\n%lld %lld\n",a[0],a[1]);
              else
                printf("2\n%lld %lld\n",a[1],a[0]);
           }
           else
           {
               if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2])
                {
                    if(a[2]!=a[1])
                     printf("2\n%lld %lld %lld\n",a[0],a[2],a[1]);
                    else
                     printf("2\n%lld %lld %lld\n",a[2],a[0],a[1]);
                }
               else
                printf("3\n%lld %lld %lld\n",a[1],a[2],a[0]);
           }
      }
    }
