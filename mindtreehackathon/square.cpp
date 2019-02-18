#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'largestMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int largestMatrix(vector<vector<int>> arr) {
    // a classic dynamic problem which i read long time  ago :)
    int n = arr.size(), bestSide = 0;
    int oxillary[501][501];

    bestSide = 0;
    for(int i = 0; i < n; i++)
            oxillary[i][0] = arr[i][0];
    for (int i = 0; i < n; i++)
      oxillary[0][i] = arr[0][i];
    
    for(int i = 1; i < n; i++)
        for(int j = 1; j <  n; j++)
            {
                if(arr[i][j] == 1)
                    oxillary[i][j] = min({oxillary[i][j - 1], oxillary[i - 1][j], oxillary[i-1][j-1]}) + 1;
                else
                    oxillary[i][j] = 0;
                if(oxillary[i][j] > bestSide)
                    bestSide = oxillary[i][j];
            }
    cout << bestSide << endl;
    return bestSide;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_rows_temp;
    getline(cin, arr_rows_temp);

    int arr_rows = stoi(ltrim(rtrim(arr_rows_temp)));

    string arr_columns_temp;
    getline(cin, arr_columns_temp);

    int arr_columns = stoi(ltrim(rtrim(arr_columns_temp)));

    vector<vector<int>> arr(arr_rows);

    for (int i = 0; i < arr_rows; i++) {
        arr[i].resize(arr_columns);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < arr_columns; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = largestMatrix(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
