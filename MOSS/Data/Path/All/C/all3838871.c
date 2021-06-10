#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;



ll d[200][200];
ll V,E;

void warshallfloyd(){
    rep(k,V)rep(i,V)rep(j,V){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    cin>>V>>E;
    rep(i,V)rep(j,V){
        d[i][j]=LLINF;
        if(i==j) d[i][j]=0;
    }
    rep(i,E){
        ll a,b,c;
        cin>>a>>b>>c;
        d[a][b]=c;
    }
    warshallfloyd();
    rep(i,V){
        if(d[i][i]<0){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    rep(i,V){
        rep(j,V){
            if(d[i][j]>=LLINF/2) cout<<"INF";
            else cout<<d[i][j];
            if(j!=V-1) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
