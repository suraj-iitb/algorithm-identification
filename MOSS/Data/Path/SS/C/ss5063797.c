#if 0
最大値INFの桁を間違っておりACできない場合がありました。1e5のような書き方をするとミスが減ると思います。
各経路について適当に一通り緩和を行い、全ての辺を
#endif

#include <iostream>
using namespace std;

int V, E, R; //ノードの数、辺の数、始点のノード番号
int S[500010], T[500010], D[500000+10],C[100010];
const int Inf=10000*100000+100;
void bellman(void);

// 入力V,E,Rがある間関数bellmanを実行する
int main(){
    while(cin >> V >> E >> R) bellman();
}

void bellman(void){
    // 入力を配列に保持
    for(int i=0; i < E; i++){
        cin >> S[i] >> T[i] >> D[i];
    }
    // スタート(0)を除く全ての距離について初期値を∞とする
    for(int i=0; i<100010; i++) C[i] = Inf;
    C[R]=0;
    for(int v=0; v < V; v++){
        bool update = false;
        // 各経路について
        for(int e=0; e<E; e++){
            int s = S[e], t=T[e], d=D[e];
            // cout << d + C[s] << "vs" << C[t] <<endl;
            // ある経路を使った方が距離が短い場合、その距離を最小距離として書き直す
            if((C[s] < Inf) && (d+C[s] < C[t])){
                C[t] = d+C[s];
                update = true;
            }
        }
        if(!update) break;
    }
    // 距離を出力


    for(int e=0; e<V; e++){
        if(C[e] < Inf) cout <<  C[e] << endl;
        else cout << "INF" << endl;
    }
}
