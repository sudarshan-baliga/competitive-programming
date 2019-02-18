#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'exam' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY v as parameter.
 */

void countthuis(vector<int> v)
{
    vector<int>::iterator score;
    priority_queue<int> x;
    int count = 0;
    for (score = v.begin(); score != v.end(); score++)
    {
        if (*score)
            *score += *(score - 1);
        else
            *score = *(score - 1) - 1;
        count++;
        cout << *score << " " << count << endl;
    }
}

int exam(vector<int> v)
{
    int best = 0;
    countthuis(v);
    // store the  cumulative scores
    vector<int>::iterator score;
    for (score = v.begin(); score != v.end(); score++)
        if (*score)
            *score += *(score - 1);
        else
            *score = *(score - 1) - 1;
    best = *(v.end() - 1);
    cout << best << endl;
    // check for zero case
    if (best < 0)
        return 0;

    for (int i = 0; i < v.size(); i++)
        if (v[i] > best - v[i])
        {
            cout << v[i] << " " << best - v[i] << " " << i << endl;
            return i + 1;
        }
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string v_count_temp;
    getline(cin, v_count_temp);

    int v_count = stoi(ltrim(rtrim(v_count_temp)));

    vector<int> v(v_count);

    for (int i = 0; i < v_count; i++)
    {
        string v_item_temp;
        getline(cin, v_item_temp);

        int v_item = stoi(ltrim(rtrim(v_item_temp)));

        v[i] = v_item;
    }

    int result = exam(v);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
