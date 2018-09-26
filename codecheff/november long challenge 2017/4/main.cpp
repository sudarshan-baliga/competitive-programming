#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t,n,a,times,rem,temp;
    char alpha[26];

    for(int i = 0;i < 26 ;i++)
        alpha[i] = i+97;


   scanf("%lld",&t);
   for(int i = 0 ; i < t;i++)
    {
        scanf("%lld %lld",&n,&a);
        if(a == 1)
        {
            printf("%lld ",n);
            for(int j = 0;j <n; j++)
                printf("a");
        }
        else
            if(a == 2)
            {
                if(n < 6)
                {
                    if(n == 1)
                        printf("1 a");
                    else
                        if(n == 2)
                            printf("1 ab");
                    else
                        if(n == 3)
                            printf("2 aab");
                    else
                        if(n == 4)
                            printf("2 aabb");
                    else
                        printf("3 aabab");
                }
                else
                {
                 rem = n%6;
                 times = n/6;
                 if(rem == 0)
                 {
                     if(times == 1)
                        printf("3 ");
                     else
                        printf("4 ");
                     for(int i = 0;i < times;i++)
                        printf("aababb");
                 }
                 else
                 if(rem == 1)
                 {   if(times == 1)
                        printf("3 aaababb");
                     else
                       {
                        printf("4 ");
                        for(int i = 0;i < times;i++)
                            printf("aababb");
                        printf("a");
                       }
                 }
                 else
                 if(rem == 2)
                 {
                     if(times == 1)
                        printf("3 aaababbb");
                     else
                     {
                        printf("4 a");

                        for(int i = 0;i < times;i++)
                            printf("aababb");
                        printf("b");
                     }
                 }
                 else
                 if(rem == 3)
                 {
                     printf("4 ");
                    for(int i = 0;i < times;i++)
                        printf("aababb");
                    printf("aab");
                 }
                 else
                    if(rem == 4)
                 {
                     printf("4 ");
                     for(int i = 0;i < times;i++)
                        printf("aababb");
                    printf("aaba");
                 }
                 else
                 {
                      printf("4 ");
                     for(int i = 0;i < times;i++)
                        printf("aababb");
                    printf("aabab");
                 }
                }

            }//2 finish
            else
            {
                temp = 0;
                printf("1 ");
                for(int i =0;i<n;i++)
                {
                    printf("%c",alpha[temp]);
                    temp = (temp+1)%a;
                }
            }
        cout<<endl;
     }

}

