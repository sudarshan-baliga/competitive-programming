/*
// Sample code to perform I/O:
 
cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}

int t, n, ti, wi;
vector<pair<int, int>> bricks; //width , thickness

int solve(int idx, int width1, int width2, int thickness1)
{
    int include, exclude;
    if (idx == n)
        return thickness1;
    // cout << width1 << " " << width2 << " "  << thickness1   << " "<< endl;
    if (width2 + bricks[idx].first <= thickness1 - bricks[idx].second)
        include = solve(idx + 1, width1 - bricks[idx].first, width2 + bricks[idx].first, thickness1 - bricks[idx].second);
    else
        include = solve(idx + 1, width1, width2, thickness1);

    return include;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int width1 = 0, thickness1 = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> ti >> wi;
            width1 += wi;
            thickness1 += ti;
            bricks.push_back({wi, ti});
        }
        sort(bricks.begin(), bricks.end());
        cout << solve(0, width1, 0, thickness1) << endl;
        bricks.clear();
    }
}