#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
using namespace std;

struct uft{
    vector<ll> par;
    uft(ll n) {
        par.resize(n);
        rep(i,n)par[i]=i;
    }

    ll find(ll a){
        if(par[a]==a){
            return a;
        }else {
            return find(par[a]);
        }
    }

    void unite(ll a,ll b){
        par[find(a)]=find(b);
    }

    bool same(ll a,ll b){
        return find(a) == find(b);
    }
};

struct edge{
    ll s,t,w;
};

bool sortw(edge a,edge b) {
    return a.w < b.w;
}

int main() {
    const ll inf = 1e12;
    ll v,e;
    cin>>v>>e;
    vector<vector<ll>> matrix(v,vector<ll>(v));
    rep(i,v){
        rep(j,v){
            if(i==j){
                matrix[i][j]=0;
            }else{
                matrix[i][j]=inf;
            }
        }
    }
    rep(i,e){
        ll s,t,w;
        cin>>s>>t>>w;
        matrix[s][t] = w;
    }
    rep(k,v){
        rep(i,v){
            rep(j,v){
                if(matrix[i][k]<inf && matrix[k][j]<inf && matrix[i][j]>matrix[i][k]+matrix[k][j]){
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
                }
            }
        }
    }
    rep(i,v){
        if(matrix[i][i] < 0){
            cout << "NEGATIVE CYCLE" <<endl;
            return 0;
        }
    }
    rep(i,v){
        rep(j,v){
            if(matrix[i][j]==inf){
                cout << "INF";
            }else {
                cout << matrix[i][j];
            }
            if(j < v-1){
                cout << " ";
            }
        }
        cout<<endl;
    }
}

