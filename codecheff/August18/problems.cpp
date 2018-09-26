#include<bits/stdc++.h>
using namespace std;

struct Contest{
    public:
        int sc, ns, originalIndex;
};

bool accordingtoScore(Contest a, Contest b){
    return (a.sc < b.sc);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, s, currentN;
    vector < pair <int,int> > result;  //for storing (n,i) for final sorting
    cin >> p >> s;
    for(int i = 0; i < p; i++) {
        Contest cont[s];
        for(int j = 0; j < s; j++)
            cin >> cont[j].sc;
        for(int j = 0; j < s; j++)
            cin >> cont[j].ns;
        sort(cont, cont + s, accordingtoScore);
        currentN = 0;
        for(int j = 0; j < s - 1;j++){
            if(cont[j].ns > cont[j+ 1].ns)
                currentN++;
        }
        result.push_back(make_pair(currentN, i + 1));
    }
    sort(result.begin(), result.end());
    for(int i = 0; i < p; i++)
        cout << result[i].second<< "\n";
}