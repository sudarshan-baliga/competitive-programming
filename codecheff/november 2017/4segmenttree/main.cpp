#include <iostream>
#define high 109

using namespace std;

typedef long long int lli;

lli arr[high], tree[3*high];

void build(lli node, lli beg, lli end) {
    if(beg > end)
        return;
    else if(beg == end) {
        tree[node] = arr[beg];
        return;
    }
    build(2*node, beg, (beg+end)/2);
    build(2*node+1, (beg+end)/2+1, end);
    tree[node] = tree[2*node] ^ tree[2*node+1];
}

void update(lli node, lli beg, lli end, lli index, lli val) {
    if(beg > end || beg > index || end < index)
        return;
    if(beg == end) {
        tree[node] = val;
        return;
    }
    update(2*node, beg, (beg+end)/2, index, val);
    update(2*node+1, (beg+end)/2+1, end, index, val);

    tree[node] = tree[2*node] ^ tree[2*node+1];
}

lli query(lli node, lli max, lli beg, lli end,lli value) {
    cout<<"hi";
    if(beg >= 1 && max >= end)
        if(tree[node] == value )
           return 1;
    if(end < 1 || beg > max)
        return 0;
    return query(2*node, max, beg, (beg+end)/2,value)+query(2*node+1, max, (beg+end)/2+1, end,value);
}


int main() {
  lli n, q, count, type, index, val, temp;
  cin >> n >> q;
  for(lli i=1;i<=n;++i)
    cin >> arr[i];
  for(lli i = 2; i <= n; i++)
      arr[i] = arr[i] ^ arr[i-1];
  build(1, 1, n);
  while(q--) {
    count = 0;
    cin >> type >> index >> val;
    if(type == 1) {
        update(1, 1, n, index, val);
    }
    else {
       {
        count += query(1, index, 1, n,val);

      }
      cout << count << endl;
    }
  }
}
