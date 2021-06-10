#include<iostream>
#define INF 99999999999999
using namespace std;
long long ans[101][101]={0};
int n,m;//n点，m边 
int floy(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans[k][j]==INF||ans[i][k]==INF)continue;
				if(ans[k][j]+ans[i][k]<ans[i][j]){
					ans[i][j]=ans[k][j]+ans[i][k];
				}
			}
		}
	}
	int f=0;
	for(int i=0;i<n;i++){
		if(ans[i][i]<0){
			f=1;
			break;
		}
	}
	if(f==0){	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans[i][j]!=INF)cout<<ans[i][j];
				else cout<<"INF";
				if(j!=n-1)cout<<' ';
			}
			cout<<endl;
		}
	}
	else cout<<"NEGATIVE CYCLE"<<endl;
}
int main(){
	cin>>n>>m;
	long long x,y,w;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			ans[i][j]=INF;
	}
	for(int i=0;i<n;i++)ans[i][i]=0;
	for(int i=0;i<m;i++){
		cin>>x>>y>>w;
		ans[x][y]=w;
	}
	floy();
} 
