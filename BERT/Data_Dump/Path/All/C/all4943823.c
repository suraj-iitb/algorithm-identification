#include <iostream>
#include<bits/stdc++.h>
#define INF (1LL<<60)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,a,b,c,dp[100][100];
vector<P> v[1000];
int main(void){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)dp[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        dp[a][b]=c;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][k]==INF||dp[k][j]==INF)continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dp[i][i]<0){cout<<"NEGATIVE CYCLE"<<endl;return 0;}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==INF)cout<<"INF";
            else cout<<dp[i][j];
            if(j!=n-1)cout<<" ";
        }
        cout<<endl;
    }
}

