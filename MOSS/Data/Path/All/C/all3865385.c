#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,m;
	int x,y,cost;
	int dp[100][100];
	int i,j,k;
	int flg;
	cin>>n>>m;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)	dp[i][j]=0;
			else		dp[i][j]=INT_MAX;
		}
	}
	for(i=0;i<m;i++){
		cin>>x>>y>>cost;
		dp[x][y]=cost;
	}
	for(k=0;k<n;k++){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(dp[i][k]!=INT_MAX&&dp[k][j]!=INT_MAX){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
	}
	flg=0;
	for(i=0;i<n;i++){
		if(dp[i][i]<0)	flg=1;
	}
	if(flg==1)	cout<<"NEGATIVE CYCLE"<<endl;
	else{
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j)	cout<<" ";
				if(dp[i][j]==INT_MAX)	cout<<"INF";
				else					cout<<dp[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
