#include <bits/stdc++.h>
using namespace std;

static const int64_t INF=2000000000000;
int V,E;
int64_t D[100][100],A[100][100];

void warshallFloyd(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                int64_t a;
                if(A[i][k]!=INF && A[k][j]!=INF) a=A[i][k]+A[k][j];
                else a=INF;
                A[i][j]=min(A[i][j],a);
            }
        }
    }
    for(int i=0;i<V;i++){
        if(A[i][i]<0){
            cout << "NEGATIVE CYCLE" << endl;
            return;
        }
    }
    
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(j) cout << " ";
            if(A[i][j]<INF) cout << A[i][j];
            else cout << "INF";
        }
        cout << endl;
    }
    return;
}

int main(){
    cin >> V >> E;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            D[i][j]=INF;
        }
    }
    for(int i=0;i<E;i++){
        int s,t;
        int64_t d;
        cin >> s >> t >> d;
        D[s][t]=d;
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i!=j) A[i][j]=D[i][j];
        }
    }
    warshallFloyd();
    return 0;
}
