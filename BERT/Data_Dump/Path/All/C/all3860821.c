#include <iostream>
#include <vector>

using namespace std;

const long INFTY = (long(1) << 40);

class Node
{
public:
    int v, cost;
    Node(int n = 0, int c = 0) : v(n), cost(c) {}
};

bool operator<(const Node &n1, const Node &n2)
{
    return n1.cost < n2.cost;
}

class WF
{
public:
    vector<vector<long>> pairs;
    WF(int N = 0, int Q = 0)
    {
        pairs.resize(N);
        for (int i = 0; i < N; i++)
        {
            pairs[i].resize(N, INFTY);
            pairs[i][i] = 0;
        }
        load_cost(Q);
    }

    void load_cost(int Q)
    {
        int u, v, c;
        for (int i = 0; i < Q; i++)
        {
            cin >> u >> v >> c;
            pairs[u][v] = c;
        }
    }

    void wf()
    {
        int N = pairs.size();
        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                if (pairs[i][k] == INFTY)
                    continue;
                for (int j = 0; j < N; j++)
                {
                    if (pairs[k][j] == INFTY)
                        continue;
                    if (pairs[i][j] > pairs[i][k] + pairs[k][j])
                    {
                        pairs[i][j] = pairs[i][k] + pairs[k][j];
                    }
                }
            }
        }
    }

    bool negative()
    {
        for (int i = 0; i < pairs.size(); i++)
            if (pairs[i][i] < 0)
                return true;
        return false;
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    WF wf(N, Q);
    wf.wf();
    if (wf.negative())
    {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (j)
                    cout << " ";
                if (wf.pairs[i][j] == INFTY)
                {
                    cout << "INF";
                }
                else
                {
                    cout << wf.pairs[i][j];
                }
            }
            cout << endl;
        }
    }
}
