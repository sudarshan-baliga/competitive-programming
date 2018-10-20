#include <iostream>
#include <algorithm>
#include<utility>
using namespace std;


int main()
{
    long long n, m, j;
    pair <long long , long long> temp;
    cin >> n >> m;
    pair<long long, long long> days[n];
    for (int i = 0; i < n; i++)
        cin >> days[i].first;
    
    for (int i = 0; i < n; i++)
        cin >> days[i].second;
    //find how many candies we have to give without using balloons
    for (int i = 0; i < n; i++)
        days[i].first = days[i].first * days[i].second;

    sort(days, days + n);
    // cout << "after sorting" << endl;
    // for (int i = 0; i < n; i++)
    //     cout << days[i].first << " ";
    // cout << endl;
    //now keep distributing the available balloons
    //always give ballon to last one(max candies) and keep rearranging
    while (m > 0)
    {
        //check if  we have completed the distribution
        if (days[n - 1].first == 0)
            break;
        // cout << "spending ballons, curent ballons" << m << endl;
        while (days[n - 1].first >= days[n - 2].first && m > 0)
        {
            days[n - 1].first -= days[n - 1].second;
            m--;
        }
        for (int i = 0; i < n; i++)
            cout << days[i].first << " ";
        cout << endl;
        // rearrange
        j = n - 2;      
        temp = days[n - 1]; 
        while (days[j].first > temp.first && j > -1)
        {
            days[j + 1] = days[j];
            --j;
        }
        days[++j] = temp;
    }
    // cout << "final result" << endl;
    // for (int i = 0; i < n; i++)
    //     cout << days[i].candies << " ";
    cout << days[n - 1].first;
}