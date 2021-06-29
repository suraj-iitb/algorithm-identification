#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

const int INF=1e18;
int V,E;
int d[110][110];

void warshall_floyd(){
    REP(k,V) REP(i,V) REP(j,V){
        if(d[i][k]==INF or d[k][j]==INF) continue;
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
}

signed main()
{
    cin>>V>>E;
    REP(i,V) REP(j,V) if(i!=j) d[i][j]=INF;
    REP(i,E){
        int a,b,c; cin>>a>>b>>c;
        d[a][b]=c;
    }

    warshall_floyd();

    REP(i,V){
        if(d[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }

    REP(i,V){
        REP(j,V){
            if(j) cout<<' ';
            if(d[i][j]==INF) cout<<"INF";
            else cout<<d[i][j];
        }
        cout<<endl;
    }
}
