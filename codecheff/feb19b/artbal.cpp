#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getBestOccurance(int freq[], string s)
{
    int bestCount = 0, changed, len = s.length(), limit = len / 2, ans = 0, required, bestChanges = 1000000, chars[26];
    for (int occurance = 1; occurance <= limit; occurance++)
    {
        if (len % occurance == 0 && len / occurance <= 26) //if we can group it
        {
            changed = 0;
            for (int j = 0; j < 26; j++)
            {
                // if freq is greater then we have to change
                if (freq[j] > occurance)
                    changed += freq[j] - occurance;
            }
            ans = changed;
            // sort the chars which are less than the occurances
            for (int j = 0; j < 26; j++)
            {
                if (freq[j] < occurance && freq[j] != 0)
                    chars[j] = freq[j];
                else
                    chars[j] = 0;
            }
            sort(chars, chars + 26, greater<int>());

            int beg = 0, end = 25;
            // get to the char from the end which is existing
            while (end > -1 && chars[end] == 0)
                end--;

            while (chars[beg] != 0)
            {
                //if previous change can cover required extra chars
                required = occurance - chars[beg];
                if (changed > 0 && (changed - required) >= 0)
                {
                    changed -= required;
                    beg++;
                }
                else
                {
                    // change all chars which is having less freq
                    changed += chars[end];
                    ans += chars[end];
                    chars[end] = 0;
                    end--;
                }
            }
            // cout << occurance << " " << ans << endl;
            if (ans <= bestChanges)
                bestChanges = ans;
        }
    }

    // corner case 1
    // check for string with only one type char
    //  find the max occuring char
    int maxOccur = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > maxOccur)
            maxOccur = freq[i];
    if (len - maxOccur < bestChanges)
        bestChanges = len - maxOccur;

    return bestChanges;
}

int main()
{
    int t, len, freq[26], maxCount = 0;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s;
        len = s.length();
        fill_n(freq, 26, 0);
        for (int j = 0; j < len; j++)
            freq[s[j] - 65]++;
        cout << getBestOccurance(freq, s) << endl;
    }
}
