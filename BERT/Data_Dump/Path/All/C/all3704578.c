//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0117&lang=jp
//FROYD-WARSHALL

#include <iostream>
#include <cstdio>
using namespace std;

const long inf = 1001001001001;
int n, m, a, b, c;
long K[100][100] = {};

void show()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (K[i][j] == inf)
            {
                cout << "INF";
            }
            else
            {
                cout << K[i][j];
            }
            if (j != n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i == j)
            {
                K[i][j] = 0;
            }
            else
            {
                K[i][j] = inf;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        //cerr << "read " << a << " " << b << " " << c << " " << d << endl;
        //cout << a << b << c << endl;
        K[a][b] = c;
        //cout << K[a][b] << endl;
    }
    //show();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (K[i][j] > K[i][k] + K[k][j] && K[i][k] != inf && K[k][j] != inf)
                {
                    K[i][j] = K[i][k] + K[k][j];
                }
            }
        }
    }
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (K[i][i] < 0)
        {
            flag = 1;
        }
    }
    if(flag){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        show();}
    //cout << K[s][g] << K[g][s] << endl;
    //cout << v - p - K[s][g] - K[g][s] << endl;
    return 0;
}

