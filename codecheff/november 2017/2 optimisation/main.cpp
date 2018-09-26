    #include <bits/stdc++.h>

    using namespace std;
    long long t,n[1000000],max1,temp,ans[2000000];
    long long calculate(long long x)  //function to get evendigit - odddigit
    {
        long long rem = 0,oddtemp = 0,eventemp = 0;
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


    long long firstrow()
    {
        long long temp2 = 0,j,count;
        temp2 = max1*2-1;

        for(int i = 1 ; i <= temp2;i++)
        {
           ans[i] = calculate(i+1);
        }
        for(int i = 1; i <= 50 ; i++)
            cout<<ans[i]<<endl;
        for(int i = 0; i < t; i++)
        {
               temp = 0;
               for(int j = 1; j <= n[i];j++)
                    temp += ans[j];
               temp2 = temp;
               for(int j =1 ; j < n[i]; j++)
               {
                 temp2 += ans[n[i]+j]-ans[j];
                 temp += temp2;
               }
               cout<<temp<<endl;

        }
    }

    int main()
    {
        scanf("%lld",&t);
        for(int i = 0; i < t; i++)
        {
         scanf("%lld",&temp);
         if(temp > max1)
            max1 = temp;
         n[i] = temp;
        }
        firstrow();

    }
