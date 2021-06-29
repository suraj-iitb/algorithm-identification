// ワーシャル フロイド法
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>

#include<queue>

using namespace std;

const int MAX_V = 100;
const int MAX_E = 9900;
const int INF = 0x7FFFFFFF;

int main(void)
{

    int V, E;
    int first, second, weight;
    bool b_negativeLoop = false;

    // 辺の重みを格納する配列
    int edgeWeight[MAX_V + 1][MAX_V + 1];

    for(int i = 0; i < MAX_V; i++)
    {
        for(int j = 0; j < MAX_V; j++)
        {
            if( i == j )
            {
                edgeWeight[i][j] = 0;
            }
            else
            {
                // 初期値として, 無効値を代入
                edgeWeight[i][j] = INF;
            }

        }
    }

    cin >> V >> E;

    for(int i = 0; i < E; i++)
    {
        cin >> first >> second >> weight;

        edgeWeight[first][second] = weight;
    }

    // ワーシャル フロイド法の実施
    for(int k = 0; k < V; k++)          // 経由する頂点
    {
        for(int i = 0; i < V; i++)      // 開始頂点
        {
            for(int j = 0; j < V; j++)  // 終了頂点
            {
                if( edgeWeight[i][k] != INF && edgeWeight[k][j] != INF )
                {
                    // 最短経路の探索
                    edgeWeight[i][j]
                        = min(edgeWeight[i][j], edgeWeight[i][k] + edgeWeight[k][j]);
                }
            }
        }
    }

    // 負の閉路の探索
    for(int p = 0; p < V; p++)
    {
        if( edgeWeight[p][p] < 0 )
        {
            // 負の閉路が存在する
            b_negativeLoop = true;
            printf("NEGATIVE CYCLE\n");
            break;
        }
    }

    if( b_negativeLoop == false )
    {
        // 結果の表示
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if( j != 0 )
                {
                    printf(" ");
                }

                if( edgeWeight[i][j] >= INF )
                {
                    printf("INF");
                }
                else
                {
                    printf("%d", edgeWeight[i][j]);
                }
            }

            printf("\n");
        }
    }

    return 0;
}

