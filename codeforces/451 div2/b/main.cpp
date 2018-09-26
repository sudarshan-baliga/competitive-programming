#include <iostream>

using namespace std;

int main()
{
   long long n,a,b,temp,flag = 0;
   cin>>n>>a>>b;
   temp = n%a;
   if(temp%b == 0)
   {
       cout<<"Yes"<<endl;
       cout<<n/a<<" "<<temp/b;
       flag = 1;
   }

}
