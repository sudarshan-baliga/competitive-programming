#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY num
 *  2. INTEGER k
 */

int minSum(vector<int> num, int k) {
    int maxEle, ans = 0;
    priority_queue<int> numbers(num.begin(), num.end());
    cout << numbers.top() << " " << k <<endl;
    while(k--)
    {
        maxEle = numbers.top();
        numbers.pop();
        numbers.push(maxEle / 2);
    }
    while(!numbers.empty())
    {
        ans += numbers.top();
        numbers.pop();
    }
    cout << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string num_count_temp;
    getline(cin, num_count_temp);

    int num_count = stoi(ltrim(rtrim(num_count_temp)));

    vector<int> num(num_count);

    for (int i = 0; i < num_count; i++) {
        string num_item_temp;
        getline(cin, num_item_temp);

        int num_item = stoi(ltrim(rtrim(num_item_temp)));

        num[i] = num_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = minSum(num, k);

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
