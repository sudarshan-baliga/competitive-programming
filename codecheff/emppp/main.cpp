#include <iostream>

using namespace std;

int main()
{
    int t,n,m,sorted[10000];
   long long minsalary[10000],companyoffer[10000][2],sortedpos[10000],companycount,salarycount,totaljob,pos;
   string qual[100000];
   bool flag;
   cin>>t;
   for(int k=0;k<t;k--)
   {
       cin>>n>>m;
       for(int i=0;i<n;i++)
        cin>>minsalary[i];
       for(int i=0;i<m;i++)
        cin>>companyoffer[i][0]>>companyoffer[i][1];

        for(int j=0;j<n;j++)
         cin>>qual[j];


       //next sort the offered salary positions


       for(int i=0;i<m;i++)
       {
             pos=i;
             for(int j=i+1;j<m;j++)
              {
                  if(companyoffer[j][0]>=companyoffer[pos][0])
                 {
                     pos=j;
                 }
              }

              companyoffer[pos][0]=0;
              sorted[i]=pos;
              cout<<pos<<" ";
       }
       //find the maximum salary that a student can get
       flag=0;
       salarycount=0;
       companycount=0;
       totaljob=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
        {   if(companyoffer[pos][1]<=0)
                {
                    pos++;
                    flag=0;
                }
               if(qual[i][pos]=='1')
               {   if(companyoffer[pos][0]<minsalary[i])
                      break;
                   else
                   if(companyoffer[pos][0]>=minsalary[i])
                   {
                       salarycount+=companyoffer[pos][0];
                       totaljob+=1;
                       companyoffer[pos][2]--;
                       if(flag==0)
                       {
                           companycount+=1;
                           flag=1;
                       }
                       break;
                   }
               }

           }
          if(pos<0)
            break;
   }
               cout<<totaljob<<" "<<salarycount<<" "<<m-companycount<<endl;

  }
}
