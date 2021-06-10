#include<iostream>
#include<cstdio>
#define ll long long

using namespace std;

const ll INF = ((1ll) << 32);
const int maxn = 100 + 10;

ll dis[maxn][maxn];

int n , m;

bool floyd()
{
    for (int k = 0 ; k < n ; k ++){
        for (int i = 0 ; i < n ; i ++){
                if (dis[i][k] == INF)
                    continue;
            for (int j = 0 ; j < n ; j ++){
                if (dis[k][j] == INF)
                    continue;
                dis[i][j] = min(dis[i][j] , dis[i][k] + dis[k][j]);
            }

        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0 ; i < n ; i ++){
        for (int j = 0 ; j < n ; j ++){
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }
    ll s , t , w;
    for (int i = 1 ; i <= m ; i ++){
        scanf("%lld %lld %lld",&s,&t,&w);
            dis[s][t] = w;
    }
    floyd();
    bool flag = false;
    for (int i = 0 ; i < n ; i ++){
        if (dis[i][i] < 0){
            flag = true;
            break;
        }
    }
    if (flag)
        printf("NEGATIVE CYCLE\n");
    else {
        for (int i = 0 ; i < n ; i ++){
            for (int j = 0 ; j < n ; j ++){
                if (dis[i][j] == INF)
                    printf("INF");
                else
                    printf("%lld",dis[i][j]);
                if (j != n - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;

}

