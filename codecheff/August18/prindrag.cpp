#include <bits/stdc++.h>
using namespace std;

int t, n, p, s[100001], MINX, MININDEX, shifted, ans[100001], rightSide, leftSide, leftSideTotal;
multiset<int, greater<int> > leftSideEle;
bool leftSideFlag;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> p;
        for (int j = 0; j < n; j++)
            cin >> s[j];
        sort(s, s + n, greater<int>());
        // if max element is >= p then it is always not possible to reach
        if (s[0] >= p)
        {
            for (int j = 0; j < n; j++)
                cout << n << " ";
            cout << "\n";
        }
        else
        {
            //find the elements which add upto to p
            MINX = 0;
            for (int j = 0; j < n; j++)
            {
                MINX += s[j];
                if (MINX >= p)
                {
                    MININDEX = j;
                    // :) be careful with the last elements u consider make sure it is as minimum as possible
                    // ex when we want to add '2'to make MINX as p we shouldnt add eg:50 when there is a num closer or
                    // equal to 2 so that chances are maximized
                    int required = p - (MINX - s[j]); //-s[j] to remove the last addition
                    int bestIndex = j, bestEle = s[j];
                    // cout << p <<" p "<< MINX <<" minx " << s[j] << " s[j" <<" required " << required << endl;
                    for (int k = j; k < n; k++)
                        if (s[k] < required)
                        {
                            bestEle = s[k - 1];
                            bestIndex = k - 1;
                            // cout << bestEle << " bestELe" <<endl;;
                            break;
                        }
                        else if (s[k] == required)
                        {
                            bestEle = s[k];
                            bestIndex = k;
                            // cout << bestEle << " bestELe" <<endl;;
                            break;
                        }
                    // bring the best Index ele closer to princess (maybe drogon :)
                    for (int k = bestIndex - 1; k > j; k--)
                        s[k + 1] = s[k];
                    s[j] = bestEle;
                    break;
                }
            }
            // cout << "MINX" << MINX << endl;
            if (MINX < p)
            {
                for (int j = 0; j < n; j++)
                    cout << 0 << " ";
                cout << "\n";
            }
            else
            {
                leftSide = 0;
                leftSideFlag = false;
                leftSideEle.clear();
                shifted = 0;
                for (int j = 0; j < n; j++)
                {
                    // cout << "LOOP " << j << " BEGINS" << endl;
                    if (j < n - MININDEX)
                        rightSide = n - MININDEX - shifted;
                    else
                        rightSide = 0;
                    // cout << rightSide << " right " << leftSide << " left"  << endl;
                    ans[j] = rightSide + leftSide;
                    // move one ele to left of princess
                    shifted += 1;

                    if (leftSideFlag)
                        leftSide += 1;
                    else
                    {
                        leftSideEle.insert(s[(MININDEX + shifted) % n]);
                        multiset<int>::iterator it;
                        if ((MININDEX + shifted > n))
                            leftSideTotal = s[(MININDEX + shifted) % n];
                        else
                            leftSideTotal = s[0];
                        int leftIndex = 0;
                        // cout << j << " it eles ";
                        for (it = leftSideEle.begin(); it != leftSideEle.end(); it++, leftIndex++)
                        {
                            // cout << *it << " ";
                            leftSideTotal += *it;
                            if (leftSideTotal >= p)
                            {
                                leftSideFlag = true;
                                leftSide = leftSideEle.size() - leftIndex;
                                // cout << "left side flag set " << leftSideTotal << " " << leftSide << endl;
                                break;
                            }
                        }
                        // cout << endl;
                    }
                }
                for (int j = 0; j < n; j++)
                    cout << ans[j] << " ";
                cout << "\n";
            }
        }
    }
}