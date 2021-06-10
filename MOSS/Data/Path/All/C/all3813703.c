#include <iostream>

using namespace std;

static const int N = 100;
static const long long INF = (1LL << 32);

class APSP {
private:
    long long cost[N][N];
    int n;
public:
    APSP() {}

    APSP(int n)
    {
        this->n = n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cost[i][j] = ((i == j) ? 0 : INF);

        int e;
        cin >> e;
        int s, t, d;
        for (int i = 0; i < e; i++)
        {
            cin >> s >> t >> d;
            cost[s][t] = d;
        }
    }

    void warshallFloyd()
    {
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if (cost[i][k] == INF)
                    continue;

                for (int j = 0; j < n; j++)
                {
                    if (cost[k][j] == INF)
                        continue;

                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    bool negative_cycle()
    {
        for (int v = 0; v < n; v++)
            if (cost[v][v] < 0)
                return true;

        return false;
    }

    void print()
    {
        if(negative_cycle())
            cout << "NEGATIVE CYCLE" << endl;
        else
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(cost[i][j] == INF)
                        cout << "INF";
                    else
                        cout << cost[i][j];
                    if(j == n - 1)
                        cout << endl;
                    else
                        cout << " ";
                }
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    APSP apsp(n);
    apsp.warshallFloyd();
    apsp.print();
}

