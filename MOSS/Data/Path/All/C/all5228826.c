#include <bits/stdc++.h>
using namespace std;

const long long INF=1LL<<60;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<long long>> dp(n,vector<long long>(n,INF));

    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        dp[a][b]=d;
    }
    for(int i=0;i<n;i++){
        dp[i][i]=0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    bool negative=false;

    for(int i=0;i<n;i++){
        if(dp[i][i]<0)negative=true;
    }

    if(negative)cout<<"NEGATIVE CYCLE"<<endl;
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j!=0)cout<<' ';
                if(dp[i][j]<INF/2)cout<<dp[i][j];
                else cout<<"INF";
            }
            cout<<endl;
        }
    }
    
    return 0;
}
