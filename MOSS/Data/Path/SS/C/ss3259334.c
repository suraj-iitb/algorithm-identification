#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long int ll;
ll V, E, R, S[500010], T[500010], D[500010];
ll C[100010];

const int INF = INT_MAX;

int main()
{
    cin >> V >> E >> R;

    // 入力
    for (int i = 0; i < E; i++)
    {
        cin >> S[i] >> T[i] >> D[i];
    }

    for (int i = 0; i < V; i++)
    {
        C[i] = i == R ? 0 : INF;
    }

    for (int t = 0; t < V; t++)
    {
        bool update = false;
        for (int i = 0; i < E; i++)
        {
            ll s = S[i], t = T[i], d = D[i];
            if (C[s] < INF && C[s] + d < C[t])
            {
                C[t] = C[s] + d;
                update = true;
            }
        }
        if (!update)
            break;
    }

    for (int i = 0; i < V; i++)
    {
        if (C[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << C[i] << endl;
        }
    }
}
