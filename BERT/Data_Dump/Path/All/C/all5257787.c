#include <vector>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

long long  INT=22202000000;
long long G[105][105],n;
int main()
{
		int t;
		cin>>n>>t;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				G[i][j]=INT;
				if(i==j){
					G[i][j]=0;
				}
			}
		}
		for(int i=0;i<t;i++){
			int u,v;
			cin>>u>>v;
			cin>>G[u][v];
		}
		for(int k=0;k<n;k++){
			for(int i=0;i<n;i++){
				if(G[i][k]==INT){
					continue;
				}
				for(int j=0;j<n;j++){
					if(G[k][j]==INT){
						continue;
					}
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
				}
			}
		}
		for(int i=0;i<n;i++){
			
				if(G[i][i]<0){
					cout<<"NEGATIVE CYCLE"<<endl;
					return 0;
				}
			
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j)cout<<" ";
				if(G[i][j]==INT){
					cout<<"INF";
				}
				else cout<<G[i][j];
			}
			cout<<endl;
		}
		return 0;
}
