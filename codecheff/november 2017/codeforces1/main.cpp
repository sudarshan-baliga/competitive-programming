#include <iostream>

using namespace std;

int main()
{
   long long n,temp1,temp2,countx1 = 0, countx2 = 0;
   cin>>n;
   for(int i = 0 ; i < n; i++){
    cin>>temp1>>temp2;
    if(temp1 < 0)
        countx1++;
    else
        countx2++;

   }
   if(countx1 == 1 || countx2 == 1)
        cout<<"Yes"<<endl;
   else
        cout<<"No"<<endl;
}
