#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimizeMeetingCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER N
 *  2. INTEGER M
 *  3. 2D_INTEGER_ARRAY costs
 */

int minimizeMeetingCost(int N, int M, vector<vector<int>> costs)
{
    int minima = costs[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (j + 1 != M && costs[i][j + 1] < 0)
                costs[i][j] += costs[i][j + 1];
            if (j != 0 && costs[i][j - 1] < 0)
                costs[i][j] += costs[i][j - 1];
            if (i + 1 != N && costs[i + 1][j] < 0)
                costs[i][j] += costs[i + 1][j];
            if (i != 0 && costs[i - 1][j] < 0)
                costs[i][j] += costs[i - 1][j];
            minima = min(minima, costs[i][j]);
        }
    cout << minima << endl;
    return minima;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string M_temp;
    getline(cin, M_temp);

    int M = stoi(ltrim(rtrim(M_temp)));

    string costs_rows_temp;
    getline(cin, costs_rows_temp);

    int costs_rows = stoi(ltrim(rtrim(costs_rows_temp)));

    string costs_columns_temp;
    getline(cin, costs_columns_temp);

    int costs_columns = stoi(ltrim(rtrim(costs_columns_temp)));

    vector<vector<int>> costs(costs_rows);

    for (int i = 0; i < costs_rows; i++)
    {
        costs[i].resize(costs_columns);

        string costs_row_temp_temp;
        getline(cin, costs_row_temp_temp);

        vector<string> costs_row_temp = split(rtrim(costs_row_temp_temp));

        for (int j = 0; j < costs_columns; j++)
        {
            int costs_row_item = stoi(costs_row_temp[j]);

            costs[i][j] = costs_row_item;
        }
    }

    int result = minimizeMeetingCost(N, M, costs);

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
