#include <iostream>
using namespace std;

const int MAX = 200;
const long long INF = (1LL<<32);
int V, E, s, t, d;
long long G[MAX][MAX];

void floyd()
{
    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            if(G[i][k]==INF) continue;
            for(int j=0; j<V; j++)
            {
                if(G[k][j]==INF) continue;
                G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
            }
        }
    }
}
bool negative()
{
    for(int i=0; i<V; i++)
    {
        if(G[i][i]<0)
            return 1;
    }
    return 0;
}
int main()
{
    cin >> V >> E;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            if(i==j) G[i][j] = 0;
            else G[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++)
    {
        cin >> s >> t >> d;
        G[s][t] = d;
    }
    floyd();
    if(negative())
        cout << "NEGATIVE CYCLE" << endl;
    else
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(j) cout << " ";
                if(G[i][j]!=INF)
                    cout << G[i][j];
                else
                    cout << "INF";
            }
            cout << endl;
        }
    }
    return 0;
}

