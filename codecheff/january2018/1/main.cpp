#include <iostream>

using namespace std;

int main()
{
  int t,a,b,c,d;
  cin>>t;
  for(int i = 0; i < t; i++){
    cin>>a>>b>>c>>d;
    if(a == b){
        if(c == d)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    if(a == c){
        if(b == d)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    if(a == d)
    {
        if(b == c)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
        cout<<"NO"<<endl;
  }
}
