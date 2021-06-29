#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;

#define MAXV 105
#define MAXE 9905
const ll INF = (1LL<<32);
int v, e;

ll G[MAXV][MAXV];

void floyd()
{
    for (int k = 0; k < v; ++k)
    {
        for (int i = 0; i < v; ++i)
        {
            if (G[i][k] == INF)
                continue; //i到k不存在路径

            for (int j = 0; j < v; ++j)
            {
                if (G[k][j] == INF)
                    continue;

                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    ll s, t, d;

    for (int i = 0; i <v; ++i)
        for (int j = 0; j <v; ++j)
            G[i][j] = (i==j?0:INF);
    
    

    for (int i = 0; i < e; ++i)
    {
        cin >> s >> t >> d;
        G[s][t] = d;
    }

    floyd();

    bool is_negative_cycle = false;
    for (int i = 0; i < v; ++i)
    {
        if (G[i][i] < 0)
        {
            is_negative_cycle = true;
            break;
        }
    }

    if(is_negative_cycle)
    {
        cout<<"NEGATIVE CYCLE"<<endl;
        return 0;
    }

    for(int i=0;i<v;++i)
    {
        for(int j=0;j<v;++j)
        {
            if(j) cout<<' ';
            if(G[i][j]==INF)
                cout<<"INF";
            else cout<<G[i][j];

            
            
        }
        cout<<endl;
    }
}
