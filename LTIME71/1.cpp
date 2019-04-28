#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t, n;
    map<string, int> occured;
    vector<pair<string, string>> names;
    string first, second;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            cin >> first >> second;
            names.push_back({first, second});
            occured[first]++;
        }
        for(int j = 0; j < n; j++)
        {
            if(occured[names[j].first] == 1)
            {
                cout << names[j].first << endl;
            }
            else
                cout << names[j].first << " " << names[j].second << endl;
        }
        names.clear();
        occured.clear();
    }
}