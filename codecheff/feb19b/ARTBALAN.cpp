#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> chars(26);

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

int getBestOccurance(int freq[], string s, int maxCount)
{
    int bestCount = 0, changed, len = s.length(), ans = 0, required, bestChanges = 1000000;
    for (int occurance = 1; occurance <= maxCount; occurance++)
    {   
        if(len % occurance == 0) //if we can group it
        {
            changed = 0;
            for(int j = 25; j >= 0; j--)
            {
                // if freq is greater, then we have to change
                if(freq[j] > occurance)
                    changed += freq[j] - occurance;     
            }
            ans = changed;
            // sort the chars which are less than the occurances
            for(int j = 0; j < 26; j++)
            {
                if(freq[j] < occurance && freq[j] != 0)
                {
                    chars[j].first = freq[j];
                    chars[j].second  = j;
                }
                else
                {
                    chars[j].first = 0;
                }
            }
            sort(chars.begin(), chars.end(), compare);

            for(int j = 0; j < 26; j++)
            {
                if(chars[j].first != 0 && chars[j].first < occurance )
                {
                    cout << ans << endl;
                    //if previous change can cover required extra chars
                    if(changed > 0)
                    {
                        required = occurance - chars[j].first;
                        if( (changed - required) >= 0)
                            changed -= required;
                        else
                        {
                            required -= changed;
                            break;
                        }
                    }
                    else
                        break;
                }
            }
            // now group the remaining chars
        
           
            cout << occurance << " " << ans << endl;
            if(ans <= bestChanges)
                bestChanges  = ans;
        }
    }

    // corner case 1
    // check for string with only one type char
    //  find the max occuring char
    int maxOccur = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] > maxOccur)
            maxOccur = freq[i];
    if(len - maxOccur < bestChanges )
        bestChanges = len - maxOccur;

    return bestChanges;
}

int main()
{
   int t, len, freq[26], maxCount = 0;;
   string s;
   cin >> t;
   for (int i = 0; i < t; i++)
   {
       cin >> s;
       len = s.length();
       fill_n(freq, 26, 0);

       for(int j = 0; j < len ;j++)
        freq[s[j] -65]++;
       // find the max occurance
       maxCount = 0;
       for(int j = 0; j < 26; j++)
        if(freq[j] > maxCount)
            maxCount = freq[j];
         cout << getBestOccurance(freq, s, maxCount) << endl;
   }
}

