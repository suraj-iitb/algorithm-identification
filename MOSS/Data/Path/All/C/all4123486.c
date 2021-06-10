#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

static const int MAX=100;
static const long long INFTY=(1LL<<32);

long long d[MAX][MAX];
int n;

void warshallFloyd(){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(d[i][k]==INFTY) continue;
            for(int j=0;j<n;j++){
                if(d[k][j]==INFTY) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    int a,b,c,e;
    cin >> n >> a;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=((i==j)?0:INFTY);
        }
    }
    for(int i=0;i<a;i++){
        cin >> b >> c >> e;
        d[b][c]=e;
    }
    
    warshallFloyd();
    bool negative=false;
    for(int i=0;i<n;i++){
        if(d[i][i]<0) negative=true;
    }
    
    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j) cout << " ";
                if(d[i][j]==INFTY) cout << "INF";
                else cout << d[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

