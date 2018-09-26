#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long a=0,b=0,len,counta = 0,countb = 0;
   int t;
   char str[100000];
   bool flaga = 0,flagb = 0;
   scanf("%d",&t);
   for(int j =0;j < t;j++)
   {
       scanf("%s",str);
       len = strlen(str);
       a = 0;b =0;counta = 0;countb = 0; flaga = 0; flagb = 0;
       for(int i = 0;i < len;i++)
       {
           if( str[i] == 'A' && !flaga)
           {
               a++;
               flaga = 1;
               countb = 0;
               flagb = 0;
           }
           else
            if(str[i] == 'A' && flaga)
           {
               counta++;
               a += counta;
               counta = 0;
           }
            else
            if(str[i] == 'B' && !flagb)
           {
               b++;
               flagb = 1;
               counta = 0;
               flaga =0;
           }
            else
            if(str[i] == 'B' && flagb)
           {
               countb++;
               b += countb;
               countb = 0;

           }
            else
            if(str[i] == '.')
           {
               if(flaga)
                    counta++;
               else
                if(flagb)
                    countb++;
           }
       }

        printf("%lld %lld\n",a,b);

   }

  return 0;
}
