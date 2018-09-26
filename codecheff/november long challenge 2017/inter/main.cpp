#include <bits/stdc++.h>

using namespace std;
bool hassh[100];
int countt = 0;
int main()
{
   char str1[100],str2[100];
   scanf("%s%s",str1,str2);
   for(int i =0;i < strlen(str1);i++)
   {
       hassh[str1[i]%26] = 1;
   }
   for(int i = 0; i < strlen(str2);i++)
   {
       if(hassh[str2[i]%26] == 0)
            countt += 1;
   }
   if(countt > 2)
   {
       printf("Cant");
   }
   else
    printf("can");
   cout<<endl;
   for(int i = 0; i < 26; i++)
    if(hassh[i] == 0)
        printf("%c",i+65);


}
