/*
O(V^3)
負辺があっても動作する。負閉路が存在する場合はそれも検出する(ある頂点 kから kへの最短路が負ならば負閉路が存在)。
↑らしい
*/

#include <bits/stdc++.h>
using namespace std;
using ll=long long int;
template<class T,class U>constexpr bool chmin(T&a,const U b){if(a<=b)return false;a=b;return true;}
template<class T,class U>constexpr bool chmax(T&a,const U b){if(a>=b)return false;a=b;return true;}


template<class T>
struct WarshallFloyd{
    int n;
    T inf;
    vector<vector<T>> table;

    inline WarshallFloyd(int n):n(n),inf(numeric_limits<T>::max()){
        init();
    }
    inline void init(){
        table.assign(n,vector<T>(n,inf));
    }

    inline void add(const int from,const int to,const T v){
        table[from][to]=v;
    }

    void build(){
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(table[i][k]==inf || table[k][j]==inf) continue;
                    chmin(table[i][j],table[i][k]+table[k][j]);
                }
            }
        }
    }
    inline T query(const int from,const int to){
        return table[from][to];
    }

    inline void adbuild(const int from,const int to,const T v){
        chmin(table[from][to],v);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(table[i][from]==inf || table[to][j]==inf) continue;
                chmin(table[i][j],table[i][from]+table[to][j]+v);
            }
        }
    }
};

signed main(){
    int v,e;
    cin>>v>>e;
    WarshallFloyd<ll> d(v);
    for(int i=0;i<v;i++){
        d.adbuild(i,i,0);
    }

    while(e--){
        int s,t;
        ll c;
        cin>>s>>t>>c;
        d.adbuild(s,t,c);
    }
    ll inf=numeric_limits<ll>::max();
    for(int i=0;i<v;i++){
        if(d.query(i,i)<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(j) cout<<" ";
            if(d.query(i,j)==inf) cout<<"INF";
            else cout<<d.query(i,j);
        }
        cout<<endl;
    }
}
