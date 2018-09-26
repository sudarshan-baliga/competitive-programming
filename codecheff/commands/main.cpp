#include <iostream>
long long n,m,command[100000][4],a[100000];
int t;

using namespace std;

int main()
{
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        for(int j=0;j<m;j++)
            command[j][3]+=1;
    for(int j=0;j<m;j++)
        cin>>command[j][0]>>command[j][1]>>command[j][2];
    for(int j=m-1;j>=0;j--){

        if(command[j][0]==2)
            {for(int k=command[j][1]-1;k<command[j][2];k++)
                command[k][3]+=command[j][3];}
        else{
            for(int k=command[j][1]-1;k<command[j][2];k++)
                {
                    a[k]=a[k]+command[j][3];
            }
        }
    }

    for(int j=0;j<n;j++)
       {  cout<<a[j]<<" ";
          a[j]=0;
       }

    cout<<endl;
    for(int j=0;j<m;j++)
            command[j][3]=0;
    }

    }

