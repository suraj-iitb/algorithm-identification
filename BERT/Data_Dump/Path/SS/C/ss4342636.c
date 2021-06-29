/*
    WRITER:kakitamasziru
*/
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
//#include <unordered_map> // unordered_map
//#include <unordered_set> // unordered_set
#include <bitset> // bitset
//#include <cctype> // isupper, islower, isdigit, toupper, tolower
//It is so troublesome that I include bits/stdc++.h !
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1001001000;
const int MOD = 1000000007;
typedef pair<int,int> P;
//NのM乗を求める(繰り返し二乗法)
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}
long long nCr(long long n, long long r) {
    long long A = 1, B = 1;
    //Aが分子Bが1/r!
    for (long long i = n - r + 1; i <= n; i++) {
        A = A * i % MOD;
    }
    for (long long i = 1; i <= r; i++) {
        B = B * i % MOD;
    }
    B = mod_pow(B, MOD - 2);
    B %= MOD;
    //Bは割るのではなく掛ける
    return (A * B) % MOD;
}

long long D[114514];
//toをfirst、costをsecondに取るグラフの辺を表す隣接リストE
vector<P> E[514514];

void dijkstra(int start){
    priority_queue<P,vector<P>,greater<P>> Q;
    for(int i = 0;i<114514;i++) D[i] = INF;
    D[start] = 0;
    //Qにはfirst:D[V]、second:V
    Q.push(make_pair(0,start));
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        int V = p.second;
        //取り出したstartからVまでの仮の最短距離>D[V]ならcontinue
        if(D[V] < p.first) continue;
        //Vについている辺を探索 E[V]はVの辺の隣接リスト
        for(int i = 0;i<E[V].size();i++){
            int to = E[V][i].first;
            int cost = E[V][i].second;
            if(D[to] > D[V] + cost){
                D[to] = D[V]+cost;
                //最短距離を更新したらQにpushする
                Q.push(make_pair(D[to],to));
            }
        }
    }
}

int main() {
    int N,M;cin >> N >> M;
    int S;cin >> S;
    for(int i = 0;i<M;i++){
        int from,to,cost;cin >> from >> to >> cost;
        E[from].push_back(make_pair(to,cost));
    }

    dijkstra(S);

    for(int i = 0;i<N;i++){
        if(D[i] == INF) cout << "INF" << endl;
        else cout << D[i] << endl;
    }
    /*
    g++ abc.cpp
    ./a.out
    */
    return 0;
}
