#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#define MOD 1000000009
/*
 * Complete the 'countMessages' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY keys
 *  2. STRING message
 */

int findPermutations(vector<string> keys, char ch) {
    for(auto itr = keys.begin(); itr != keys.end(); itr++)
    {
        for(int i = 0; i < (*itr).length(); i++)
        {
            if( (*itr)[i] == ch)
            {
              if ((*itr).length() == 3 || ((*itr).length() == 4 && i != 3 )) {
                    switch (i) {
                        case 0:
                            return 1;
                        case 1:
                            return 2;
                        case 2:
                            return 4;
                    }
                }
                return 7;
            }
        }
    }
    return 0;
}

int countMessages(vector<string> keys, string message) {
    long long ans = 1;
    for(char ch: message)
    {
        if(ch != ' '){
            int x = findPermutations(keys, ch);
            ans = ( (ans % MOD) * (findPermutations(keys, ch) % MOD)) % MOD;
            // cout << ans << " " << ch << " "<< x << endl; 
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string keys_count_temp;
    getline(cin, keys_count_temp);

    int keys_count = stoi(ltrim(rtrim(keys_count_temp)));

    vector<string> keys(keys_count);

    for (int i = 0; i < keys_count; i++) {
        string keys_item;
        getline(cin, keys_item);

        keys[i] = keys_item;
    }

    string message;
    getline(cin, message);

    int result = countMessages(keys, message);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
