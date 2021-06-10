#if 0
#endif

#include <iostream>
#include <string>
using namespace std;

int /* 頂点の数, 最大100,000 */ POINT_NUM,
    /* 辺の数, 最大500,000 */ NODE_NUM,
    /* 始点 */ start,
    S[500010], T[500010], D[500010];
int C[100010]; // 各頂点までの最短距離の上限
const int Inf = 10000 * 100000 + 100;

int main()
{
    cin >> POINT_NUM >> NODE_NUM >> start;
    if (NODE_NUM == 0)
    {
        for (int i = 0; i < POINT_NUM; i++)
        {
            cout << (i == start ? to_string(0) : "INF") << endl;
        }
        return 0;
    }
    for (int i = 0; i < NODE_NUM; i++)
    {
        // 変数の入力
        cin >> S[i] >> T[i] >> D[i];
    }
    for (int i = 0; i < POINT_NUM; i++)
    {
        // Cの初期化
        C[i] = i != start ? Inf : 0;
    }
    for (int t = 0; t < POINT_NUM; ++t)
    {
        bool update = false;
        for (int i = 0; i < NODE_NUM; ++i)
        {
            // t: 頂点
            // i: ノードの値
            int s = S[i], t = T[i], d = D[i];
            if (C[s] < Inf && C[t] > C[s] + d)
            {
                C[t] = C[s] + d;
                update = true;
            }
        }
        if (!update)
            break;
    }
    for (int i = 0; i < POINT_NUM; i++)
    {
        cout << (C[i] == Inf ? "INF" : to_string(C[i])) << endl;
    }
}

