#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    int V, E, R;
    cin >> V >> E >> R;
    vector<int> d(V, 2e9);
    d[R] = 0;
    vector<int> S(E), T(E), D(E);
    for (int i = 0; i < E; i++) cin >> S[i] >> T[i] >> D[i];
    for (int t = 0; t < V; t++)
    {
        bool no_chng = true;
        for (int i = 0; i < E; i++)
        {
            if (d[S[i]] < 2e9 && d[T[i]] > d[S[i]] + D[i])
            {
                d[T[i]] = d[S[i]] + D[i];
                no_chng = false;
            }
        }
        if (no_chng) break;
    }
    for (auto i : d) cout << ((i == 2e9) ? "INF" : to_string(i).c_str()) << endl;
    return 0;
}
