#include <bits/stdc++.h>
long long t,n,q,a[100000][4],zero,one,temp,two[4],twotemp,ans,ten[4],tentemp;
bool flag = 0;

using namespace std;
struct coef{
long long a[4];
};
bool compare(coef x, coef y)
{
    if(x.a[3]!=y.a[3])
    {
        printf("hi");
        return x.a[3]< y.a[3];

    }
    else
    if(x.a[2]!=y.a[2])
    {   cout<<"byr";
        return x.a[2]< y.a[2];
    }
    else
    if(x.a[1]!=y.a[1])
    {
        return x.a[1]< y.a[1];
    }
    else
    if(x.a[0]!=y.a[0])
    {
        return x.a[0]< y.a[0];
    }
    else
        return 0;
}
/*void fun(long long temp)
{
    long long ans,ans1=LONG_MAX;
    for(int j = 0; j< n;j++)
    {
        ans = a[j][0]+a[j][1] * temp + a[j][2] * temp * temp+ a[j][3] * temp * temp *temp;
        if(ans < ans1)
        {
            ans1 = ans;
            two[0]=  a[j][0];
            two[1]=  a[j][1];
            two[2]=  a[j][2];
            two[3]=  a[j][3];
        }
    }
    flag = 1;
    cout<<ans1<<endl;
}*/

int main()
{

    scanf("%lld",&t);
    for(int i = 0;i < t; i++)
    {
        flag = 0;
        two[0] = two[1] = two[2] = two[3] = 0;
        one = LONG_MAX; zero = LONG_MAX; twotemp =LONG_MAX,tentemp = LONG_MAX;
        cin>>n;
        struct coef s[n];
        for(int j = 0;j < n;j++)
        {
                scanf("%lld%lld%lld%lld",&s[j].a[0],&s[j].a[1],&s[j].a[2],&s[j].a[3]);
                if(s[j].a[0]<zero)
                    zero = s[j].a[0];
                temp = s[j].a[0]+s[j].a[1]+s[j].a[2]+s[j].a[3];
                if(temp < one )
                {
                    one = temp;

                }
                temp = s[j].a[0] + s[j].a[1] * 1000+ s[j].a[2] * 1000000 + s[j].a[3] * 1000000000;
                if(temp < twotemp)
                {
                    two[0] = s[j].a[0];
                    two[1] = s[j].a[1];
                    two[2] = s[j].a[2];
                    two[3] = s[j].a[3];
                    twotemp = temp;
                   // printf("two");
                }


        }
        sort(s,s+n,compare);
        scanf("%lld",&q);
        /*scanf("%lld",&temp);
        fun(temp);*/
        for(int k =0;k < q;k++ )
        {
            scanf("%lld",&temp);
            if(temp == 0)
                cout<<zero<<endl;
            else
                if(temp == 1)
                    cout<<one<<endl;
            else
               {

                printf("%lld\n",min((s[0].a[0]+s[0].a[1] * temp + s[0].a[2] * temp * temp+ s[0].a[3] * temp * temp *temp),(two[0]+two[1]*temp+two[2]*temp*temp+two[3]*temp*temp*temp)));
               }

           /* if(temp == 0)
                printf("%lld",zero);
            else
            if(temp == 1)
                printf("%lld",one);
            else
            printf("%lld",two[0]+two[1] * temp + two[2] * temp * temp+ two[3] * temp * temp *temp);
            printf("\n");
            */
        }
     }
     return 0;

}
