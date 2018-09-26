    #include <bits/stdc++.h>

    using namespace std;
    long long t,n,m,evenred,oddred;
    string cake[10000];

    int opti( char x, char y,long long cost1, long long cost2)
    {
        long long flag,xcount = 0,ycount = 0;
         for(int i  = 0; i < n; i ++)
         {
             if(i%2 == 0)
                flag = 1;
             else
                flag = 0;
            for(int j = 0; j < m ;j++)
            {
                if(cake[i][j] != x && flag && j%2 == 0)
                    xcount += cost1;
                else
                if(cake[i][j] != y && flag && j%2 == 1)
                    {
                        ycount = ycount + cost2;
                    }
                else
                if(cake[i][j] == x && !flag && j%2 ==0)
                    ycount += cost2;
                else
                 if(cake[i][j] != x && !flag && j%2 ==1)
                    xcount += cost1;
                cout<<xcount<<"  "<<ycount<<" "<<flag<< " " <<j<<endl;
            }
         }

         return xcount+ycount;
    }

    int main()
    {

       scanf("%lld",&t);
       for(int i = 0; i < t ; i++)
       {
           oddred = evenred = 0;
           scanf("%lld%lld",&n,&m);

           for(int i  = 0; i < n; i ++)
           {
            cin>>cake[i];
           }
           oddred = opti('R','G',5,3);
           evenred = opti('G','R',3,5);
           cout<<min(oddred,evenred)<<endl;
           for(int j = 0; j<n;j++)
            cout<<cake[j];

       }

    }
