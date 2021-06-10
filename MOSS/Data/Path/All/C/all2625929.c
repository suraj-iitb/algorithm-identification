#include "bits/stdc++.h"
using namespace std;
int main()
{
    int v, e;
    long long inf = 100000000000000;
    scanf("%d %d", &v, &e);
    vector<vector<long long>> a(v, vector<long long>(v, inf));
    for (int i = 0, s, t, d; i < e; i++)
    {
        scanf("%d %d %d", &s, &t, &d);
        a[s][t] = d;
    }
    for (int i = 0; i < v; i++)
    {
        a[i][i] = 0;
    }
    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v && a[j][i] != inf; k++)
            {
                if (a[i][k] != inf)
                {
                    a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
                }
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (a[i][i] < 0)
        {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }
    for (int i = 0; i < v; i++)
    {
        printf(a[i][0] == inf ? "INF" : "%lld", a[i][0]);
        for (int j = 1; j < v; j++)
        {
            printf(a[i][j] == inf ? " INF" : " %lld", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
