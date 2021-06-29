#include <bits/stdc++.h>
using namespace std;

template<typename T>
void Warshall_Floyd(vector<vector<T>> &d,T id){
    int n=d.size();
    for (int k=0;k<n;++k){
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j){
                if (d[i][k]==id||d[k][j]==id) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C

void GRL_1_C(){
    const long long inf=1e18;
    int V,E; cin >> V >> E;
    vector<vector<long long>> ans(V,vector<long long>(V,inf));
    for (int i=0;i<V;++i) ans[i][i]=0;
    for (int i=0;i<E;++i){
        int s,t,d; cin >> s >> t >> d;
        ans[s][t]=d;
    }

    Warshall_Floyd(ans,inf);
    for (int i=0;i<V;++i){
        if (ans[i][i]<0){
            cout << "NEGATIVE CYCLE" << '\n';
            return;
        }
    }
    for (int i=0;i<V;++i){
        for (int j=0;j<V;++j){
            if (ans[i][j]==inf) cout << "INF";
            else cout << ans[i][j];
            cout << (j+1==V?'\n':' ');
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    GRL_1_C();
}
