#include <bits/stdc++.h>

using namespace std;
int l,r,hashh[100];

int main()
{
    scanf("%d%d",&l,&r);
    for(int i = 2; i<=r;i++)
    {
        for(int j = i+i; j <=r ;j = j+i)
        {
            hashh[j] = 1;
        }
    }
    for(int i = l; i <=r; i++)
    {
        if(hashh[i]==0)
            printf("%d ",i);
    }
}
