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
 map<pair<int,int>, int> permutations; //which key and how many times gives these many permutations

int findPermutations(int stroke, int count) {
    
                    switch (i) {
                        case 0:
                            return 1;
                        case 1:
                            return 2;
                        case 2:
                            return 3;
                    }
}

int countMessages(vector<string> keys, string message) {
    long long ans = 1, repeatCount, perm, stroke;
    int sequence[1000000],idx = 0, len;
    map<char, int> keyboard;
    len = message.length();

    //lets create map of number pressed  and character
    for(auto idx = 0; idx != keys.size(); idx++)
    {
        for(char ch: keys[idx])
            keyboard[ch] = idx;
    }

    //build the number of different permutations for each key
    for(auto idx = 0; idx != keys.size(); idx++)
    {
        if(keys[idx].size() == 3)
        {
            permutations[{idx, 1}] = 1;
            permutations[{idx, 2}] = 2;
            permutations[{idx, 3}] = 4;
        }
        else
        {
          permutations[{idx, 1}] = 1;
          permutations[{idx, 2}] = 2;
          permutations[{idx, 3}] = 4;
          permutations[{idx, 4}] = 7;
        }
    }

    //build the number sequence
    for(char ch: message)
    {
        if(ch != ' ')
            sequence[idx++] = keyboard[ch];
        else
            sequence[idx++] = 1;
    }



    //find the ans for different findPermutations
    while(idx != len)
    {
        repeatCount = 1;
        stroke = sequence[idx];
        if(idx == len - 1)
            perm = findPermutations(stroke, 1);
        else
        {
            while(idx != len-1 &&  sequence[idx] == sequence[idx + 1])
            {
                idx +=1;
                repeatCount += 1;
            }
            perm = 
        }
        ans = ( (ans % MOD) * (perm % MOD)) % MOD;
    }

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
