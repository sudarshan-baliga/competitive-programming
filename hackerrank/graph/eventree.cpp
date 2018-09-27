#include<iostream>
#include<utility>
#include<vector>
using namespace std;


int main(){
    int n, e, u, v, ans;
    cin >> n >> e;
    vector <pair<int, int>> nodes = vector <pair<int, int>>(n); //first is root second is num of         childern
    for(int i = 0; i < n; i++){
        nodes[i].first = -1;
        nodes[i].second = 1;
    }
    for(int i = 0; i < e;i++){
        cin >> u >> v;
        nodes[u-1].first = v -1 ;
    }
    // from the end of the tree go on adding number of the children to parent     
    for(int i = n -1; i >-1; i--)
        if(nodes[i].first != -1)
            nodes[nodes[i].first].second += nodes[i].second;
    // calculate the ones which have even children in subtree
    ans = 0;
    for(int i = 0; i < n; i++)
        if(nodes[i].first != -1 && nodes[i].second % 2  == 0)
            ans++;
    cout << ans << endl;
    
}
