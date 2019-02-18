#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


#define inf 100000
/*
 * Complete the 'findCapitalCity' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER robber_distance
 *  2. WEIGHTED_INTEGER_GRAPH city
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int findCapitalCity(int robber_distance, int city_nodes, vector<int> city_from, vector<int> city_to, vector<int> city_weight) {
    int dist[1001][1001], capital, leastRobbers, curRobbers;
    //initialize all distance as inf
    for(int i = 0; i < 1001; i++)
        for(int j = 0; j < 1001; j++)
            dist[i][j] = inf;
    //update the distance as given in input
    for(int i = 0; i < city_from.size(); i++ ){
        dist[city_from[i]][city_to[i]] = city_weight[i];
        dist[city_to[i]][city_from[i]] = city_weight[i];
    }

    //apply floyds algo
    for(int k = 1; k <= city_nodes; k++)
        for(int i = 1; i <= city_nodes; i++)
            for(int j = 1; j <= city_nodes; j++)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    //find robber
    capital = 1;
    leastRobbers = 9999;
    for(int i = 1; i <= city_nodes; i++)
    {   
        curRobbers = 0;
        for(int j = 1;j <= city_nodes; j++)
            if(dist[i][j] <= robber_distance)
                curRobbers++;
        cout << curRobbers << " " << i << endl;
        if(leastRobbers >= curRobbers)
        {
            leastRobbers = curRobbers;
            capital = i;
        }
    }
    // cout << capital << endl;
    return capital;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string robber_distance_temp;
    getline(cin, robber_distance_temp);

    int robber_distance = stoi(ltrim(rtrim(robber_distance_temp)));

    string city_nodes_edges_temp;
    getline(cin, city_nodes_edges_temp);

    vector<string> city_nodes_edges = split(rtrim(city_nodes_edges_temp));

    int city_nodes = stoi(city_nodes_edges[0]);
    int city_edges = stoi(city_nodes_edges[1]);

    vector<int> city_from(city_edges);
    vector<int> city_to(city_edges);
    vector<int> city_weight(city_edges);

    for (int i = 0; i < city_edges; i++) {
        string city_from_to_weight_temp;
        getline(cin, city_from_to_weight_temp);

        vector<string> city_from_to_weight = split(rtrim(city_from_to_weight_temp));

        int city_from_temp = stoi(city_from_to_weight[0]);
        int city_to_temp = stoi(city_from_to_weight[1]);
        int city_weight_temp = stoi(city_from_to_weight[2]);

        city_from[i] = city_from_temp;
        city_to[i] = city_to_temp;
        city_weight[i] = city_weight_temp;
    }

    int result = findCapitalCity(robber_distance, city_nodes, city_from, city_to, city_weight);

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
