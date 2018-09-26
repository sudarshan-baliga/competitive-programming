#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n, u, v, m;
vector<vector<int> > graph;
vector<int> moves;
vector<bool> visit;
queue<int> fifo;

void bfs()
{
    while (!fifo.empty())
    {
        int a = fifo.front();
        fifo.pop();
        for (int i = 0; i < graph[a].size(); i++)
        {
            int b = graph[a][i];
            if (!visit[b])
            {
                visit[b] = true;
                moves[b] = min(moves[b], moves[a] + 1);
                fifo.push(b);
            }
        }
    }
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // initialize
        moves = vector<int>(101, 100);
        visit = vector<bool>(101, false);
        graph = vector<vector<int> >(101);

        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 6 && i + j <= 100; j++)
            {
                graph[i].push_back(i + j);
            }
        }
        //get the ladders and update the graph
        cin >> n;
        for (int k = 0; k < n; k++)
        {
            cin >> u >> v;
            // at max u - 6 th block can reach u because max u can get on dice is 6
            int j = u - 6;
            if (j < 1)
                j = 1;
            for (; j < u; j++)
                for (int k = 0; k < graph[j].size(); k++)
                    // find when does current block move to u
                    if (graph[j][k] == u)
                    {
                        // make it move to v
                        graph[j][k] = v;
                        break;
                    }
        }
        //get the snakes and update the graph
        cin >> m;
        for (int k = 0; k < m; k++)
        {
            cin >> u >> v;
            // at max u - 6 th block can reach u because max u can get on dice is 6
            int j = u - 6;
            if (j < 1)
                j = 1;
            for (; j < u; j++)
                for (int k = 0; k < graph[j].size(); k++)
                    // find when does current block move to u
                    if (graph[j][k] == u)
                    {
                        // make it move to v
                        graph[j][k] = v;
                        break;
                    }
        }

        // find the shortest path to reach 100th block. Use bfs since there are no weights
        fifo.push(1);
        visit[1] = true;
        moves[1] = 0;
        bfs();
        if(moves[100] > 17)
        {
            cout << -1 << endl;
        }
        else
        {
           cout << moves[100]<< endl;
        }
    }
}