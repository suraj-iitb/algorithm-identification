//Dijkstra
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1001001001;

int main()
{
    /*
    std::priority_queue<
        int,              // 要素の型はint
        std::vector<int>, // 内部コンテナはstd::vector (デフォルトのまま)
        std::greater<int> // 昇順 (デフォルトはstd::less<T>)
        >
        que;
    */

    int n, m, r;
    cin >> n >> m >> r;
    int d[n];
    bool flag[n] = {};
    int confirmed = 0;
    //    priority_queue<pair<int, int>> q;
    std::priority_queue<
        pair<int, int>,              // 要素の型はint
        std::vector<pair<int, int>>, // 内部コンテナはstd::vector (デフォルトのまま)
        std::greater<pair<int, int>> // 昇順 (デフォルトはstd::less<T>)
        >
        q;
    //int S[m], T[m], D[m];
    vector<vector<pair<int, int>>> edge(n);
    for (int i = 0; i < m; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        /*
        S[i] = s;
        T[i] = t;
        D[i] = d;
        */
        edge.at(s).push_back(make_pair(t, d));
    }
    for (int i = 0; i < n; i++)
    {
        d[i] = inf;
        //q.push(make_pair(inf, i));
    }
    d[r] = 0;
    q.push(make_pair(0, r));

    while (!q.empty() && confirmed != n)
    {
        pair<int, int> v = q.top();
        q.pop();

        if (!flag[v.second])
        {
            //cout << v.second << " " << v.first << endl;
            flag[v.second] = true;
            confirmed++;
            /*
            for (int i = 0; i < m; i++)
            {
                if (S[i] == v.second)
                {
                    if (d[T[i]] > d[S[i]] + D[i])
                    {
                        d[T[i]] = d[S[i]] + D[i];
                        q.push(make_pair(d[T[i]], T[i]);
                    }
                }
            }
            */
            for (int i = 0; i < edge.at(v.second).size(); i++)
            {
                if (d[edge.at(v.second).at(i).first] > d[v.second] + edge.at(v.second).at(i).second)
                {
                    d[edge.at(v.second).at(i).first] = d[v.second] + edge.at(v.second).at(i).second;
                    q.push(make_pair(d[edge.at(v.second).at(i).first], edge.at(v.second).at(i).first));
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (d[i] == inf)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << d[i] << endl;
        }
    }

    return 0;
}

