#include <bits/stdc++.h>

using namespace std;

long long len1,counta,countb,temp,aattempt = 5,battempt = 5;
bool flag = 0;
int main()
{

  string str;
  while(getline(cin,str))
  {
      counta = 0; countb = 0; flag = 0; aattempt = 5; battempt = 5;
      for(int i = 0; i < 10;i++)
      {
          if(  i%2 == 0 )
          {
              aattempt--;
              if(str[i] == '1' )
                 counta += 1;
                if(countb + battempt < counta)
                {
                    cout<<"TEAM-A"<<" "<<10-(aattempt+battempt)<<endl;
                    flag = 1;
                    break;
                }
                else
                if(counta + aattempt < countb )
                    {
                        cout<<"TEAM-B"<<" "<<10-(aattempt+battempt)<<endl;
                        flag = 1;
                        break;
                    }

               }

           else
            {
              battempt--;
              if(str[i] == '1' )
               countb++;
              if(countb + battempt < counta)
                {
                    cout<<"TEAM-A"<<" "<<10-(aattempt+battempt)<<endl;
                    flag = 1;
                    break;
                }
                else
                if(counta + aattempt < countb )
                    {
                        cout<<"TEAM-B"<<" "<<10-(aattempt+battempt)<<endl;
                        flag = 1;
                        break;
                    }

               }
          }



      //for end

      if(!flag)
      {
          counta = 5; countb = 5;
          for(int i = 10;i < 19; i+=2)
          {
              if(str[i] > str[i+1])
              {
                  counta += 2;
                  flag = 1;
                  cout<<"TEAM-A"<<" "<<counta+countb<<endl;
                  break;
              }
              else
                if(str[i+1] > str[i] )
              {
                  flag = 1;
                  countb += 2;
                  cout<<"TEAM-B"<<" "<<countb+counta<<endl;
                  break;
              }
              counta += 1;
              countb += 1;
          }
      }
      if(!flag)
        printf("TIE\n");

  }//while end
}
