#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// #define DEBUG

const int maxint = 1e9;
struct timestamp;
vector<int> shortest;
vector<vector<pair<int, int>>> connective;

void djkstra(int x)
{
    vector<int> search = {x};
    vector<int> new_search;
    shortest[x] = 0;
    int v, d;
    while (!search.empty())
    {
        for (auto itr = search.begin(); itr != search.end(); itr++)
        {
            for (auto itr2 = connective[*itr].begin(); itr2 != connective[*itr].end(); itr2++)
            {
                v = itr2->first, d = itr2->second;
                if (shortest[v] > d + shortest[*itr])
                {
                    shortest[v] = d + shortest[*itr];
                    new_search.push_back(v);
                }
            }
        }
        search.clear();
        search = new_search;
        new_search.clear();
    }
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, m, r, s, t, d;
    cin >> n >> m >> r;
    connective.resize(n);
    for (int i = 0; i < n; i++)
    {
        shortest.push_back(maxint);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> d;
        connective[s].push_back(make_pair(t, d));
    }
    djkstra(r);
    for (int i = 0; i < n; i++)
    {
        if (shortest[i] == maxint)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << shortest[i] << endl;
        }
    }

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)
// for (int j = 0; j < m; j++)
