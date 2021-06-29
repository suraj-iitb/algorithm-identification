#include <bits/stdc++.h>
using namespace std;

long long wf[110][110] = {0};

long long INF = 1ll<<59;

int main(){
    long long V,E;
    cin >> V >> E;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            wf[i][j] = INF;
            if(i==j) wf[i][j] = 0;
        }
    }

    for(int i=0;i<E;i++){
        long long s,t,d;
        cin >> s >> t >> d;
        wf[s][t] = d;
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                wf[i][j] = min(wf[i][j],wf[i][k]+wf[k][j]);
            }
        }
    }
    bool flag = true;
    for(int i=0;i<V;i++){
        if(wf[i][i]<0) flag = false;
    }
    if(flag){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(wf[i][j]>1ll<<58) cout << "INF";
                else cout << wf[i][j];
                if(j<V-1) cout << " ";
            }
            cout << endl;
        }
    }else{
        cout << "NEGATIVE CYCLE" << endl;
    }
}
