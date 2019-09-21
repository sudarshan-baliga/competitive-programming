#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll tree[500050];
ll a[200010];
void build_tree(ll node,ll l,ll r,ll n)
{
    if(l==r)
    {
        tree[node]=a[l];
        return ;
    }
    ll mid=(l+r)/2;
    build_tree(node*2,l,mid,n);
    build_tree(node*2+1,mid+1,r,n);
    if((n-(ll)log2(node))&1)
        tree[node]=tree[node*2]|tree[node*2+1];
    else
        tree[node]=tree[node*2]^tree[node*2+1];
}
void update_tree(ll node,ll a,ll b,ll p,ll x,ll n)
{
    //cout<<node<<endl;
    if(p<a||p>b)
        return ;
    if(a==b)
    {
        tree[node]=x;
        return;
    }
    ll mid=(a+b)/2;
    update_tree(node*2,a,mid,p,x,n);
    update_tree(node*2+1,mid+1,b,p,x,n);
    if((n-(ll)log2(node))&1)
        tree[node]=tree[node*2]|tree[node*2+1];
    else
        tree[node]=tree[node*2]^tree[node*2+1];
}
int main()
{
    //cout<<(1|6|3|5);
    ll n,q;
    cin>>n>>q;
    ll m=pow(2,n);
    for(int i=1;i<=m;i++)
        cin>>a[i];
    build_tree(1,1,m,n);
    //cout<<"hello"<<endl;
    for(int i=0;i<q;i++)
    {
        //cout<<i<<endl;
        ll p,x;
        cin>>p>>x;
        update_tree(1,1,m,p,x,n);
        cout<<tree[1]<<endl;
    }
    return 0;
}