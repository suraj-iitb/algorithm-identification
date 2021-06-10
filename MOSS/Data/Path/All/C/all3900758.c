#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define MAX 100
#define vmax 10000
#define sentinel 2000000000
#define INF (1<<30)
constexpr long long int inf = 100000000000000000;
constexpr long long int rinf = -(INT64_MAX);
static const int NIL=-1;

//cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);

int V,E;
ll d[MAX][MAX];

bool floyd(){
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            if(d[i][k]==inf) continue;
            for(int j=0;j<V;j++){
                if(d[k][j]==inf) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=0;i<V;i++){
        if(d[i][i]<0) return true;;
    }
    return false;
}


int main() {
   int s,t,c;
   cin>>V>>E;
   for(int i=0;i<V;i++){
       for(int j=0;j<V;j++){
           d[i][j]=((i==j) ? 0 : inf);
       }
   }
   for(int i=0;i<E;i++){
       cin>>s>>t>>c;
       d[s][t]=c;
   }
   
   if(floyd()){
       cout<<"NEGATIVE CYCLE"<<endl;
       return 0;
   }

   for(int i=0;i<V;i++){
       for(int j=0;j<V;j++){
           if(j) cout<<" ";
           if(d[i][j]==inf){
               cout<<"INF";
            }else{
                cout<<d[i][j];
            }
        }
        cout<<endl;
   }
    return 0;
}




