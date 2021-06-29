#include "bits/stdc++.h"
#define REP(i, n, N) for(ll i=n; i<N; i++)
using namespace std;
typedef long long ll;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
// 第２引数の型を配列の要素の型に合わせないとうまくいかない
// long long d[20][20];
// Fill(d, (long long)100);
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    ll INF = 1e18;
    int v, e;
    cin >> v >> e;
    ll dist[100][100];
    Fill(dist, INF);
    REP(i, 0, v){
        dist[i][i] = 0;
    }


    REP(i, 0, e){
        int a, b, d;
        cin >> a >> b >> d;
        dist[a][b] = d;
    }

    REP(i, 0, v){
        REP(j, 0, v){
            if(dist[j][i]==INF) continue;
            REP(k, 0, v){
                if(dist[i][k]==INF) continue;
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    REP(i, 0, v){
        if(dist[i][i]<0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    REP(i, 0, v){
        REP(j, 0, v){
            if(j!=0) cout << " ";
            if(1e18 == dist[i][j]){
                cout << "INF";
            }else{
                cout << dist[i][j];
            }
        }
        cout << endl;
    }
}
