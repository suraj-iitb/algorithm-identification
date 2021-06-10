#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

static const int MAX = 100000;
static const long int INF = 5000000001;
static const int NEW = 0;
static const int ACTIVE = 1;
static const int FINISHED = 2;

vector<pair<int, int>> adj[MAX];
int V, E, r;
int status[MAX];
long int distances[MAX];

void dijkstra(int r)
{

    for (int j = 0; j < V; j++)
    {
        status[j] = NEW;
        distances[j] = INF;
    }

    priority_queue<pair<int, int>> PQ;

    distances[r] = 0;
    PQ.push(make_pair(0, r));
    status[r] = 0;

    while (!PQ.empty())
    {
        pair<int, int> f = PQ.top();
        PQ.pop();

        int u = f.second;
        status[u] = FINISHED;

        if (distances[u] < f.first * (-1))
        {
            continue;
        }

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            if (status[v] == FINISHED)
            {
                continue;
            }
            if (distances[v] > distances[u] + adj[u][i].second)
            {
                distances[v] = distances[u] + adj[u][i].second;
                PQ.push(make_pair(distances[v] * (-1), v));
                status[v] = ACTIVE;
            }
        }
    }
}

int main()
{

    cin >> V >> E >> r;

    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;

        adj[s].push_back(make_pair(t, d));
    }

    //status.assign(V, NEW);
    //distances.assign(V, INF);
    dijkstra(r);

    for (int i = 0; i < V; i++)
    {
        if (distances[i] == INF)
            cout << "INF" << endl;
        else
            cout << distances[i] << endl;
    }

    return 0;
}

