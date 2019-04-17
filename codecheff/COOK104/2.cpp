// https://www.codechef.com/viewsolution/23658836
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;

using namespace std;

bool comp(vector<pair<ll,ll>> a,vector<pair<ll,ll>> b)
{
    if(a.size()>b.size())
        return 1;
    return 0;    
}

int main()
{
   FAST/**/

   ll t;
   cin>>t;
   
   while(t--)
   {
       ll n;
       cin>>n;
       
       ll arr[n];
       
       for(ll i=0;i<n;i++)
            cin>>arr[i];
       
        unordered_map<ll,ll> ma;  
        ll ind = 0;
        for(ll i=0;i<n;i++)
            ma[arr[i]] = -1;
        for(ll i=0;i<n;i++)
        {
            if(ma[arr[i]] == -1)
            {
                ma[arr[i]] = ind;
                ind++;
            }
        }
        
        vector<pair<ll,ll>> v[ma.size()];
        for(ll i=0;i<n;i++)
        {
            ll j = ma[arr[i]];
            v[j].push_back(make_pair(arr[i], i));
        }
        
        sort(v, v+ma.size(), comp);
        
        ll siz = ma.size();
        
        if(v[0].size()>n/2)
        {
            cout<<"No"<<"\n";
            continue;
        }
        
        cout<<"Yes"<<"\n";
        
        vector<pair<ll,ll>> aux;
        
        for(ll i=0;i<siz;i++)
            for(auto it = v[i].begin();it!=v[i].end();it++)
                aux.push_back(*it);
        ll final[n];
        
        for(ll cp = 0;cp<n;cp++)
        {
            ll temp = v[0].size();
            ll ind1 = aux[cp].second;
            ll ind2 = aux[(cp + temp)%n].second;
            final[ind1] = arr[ind2];
        }
        
        for(ll i=0;i<n;i++)
            cout<<final[i]<<" ";
        cout<<"\n";    
   }
   
   return 0;
}