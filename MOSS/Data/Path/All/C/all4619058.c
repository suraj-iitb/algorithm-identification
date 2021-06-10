#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAX=105;
const LL INF=1LL<<31;
LL G[MAX][MAX],A[MAX][MAX];
int V,E;
void init(int type){
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			if(type){
				if(i!=j)G[i][j]=INF;
				else G[i][j]=0;
			}else 
				A[i][j]=G[i][j];
		}
	}
}
void warshallFloyd(){
	for(int k=0;k<V;k++)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				if(A[i][k]!=INF&&A[k][j]!=INF)
					A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
}
int main(){
	init(1);
	int s,t,d;
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>s>>t>>d;
		G[s][t]=d;
	}
	init(0);
	warshallFloyd();
	int flag=true;
	for(int i=0;i<V;i++){
		if(A[i][i]<0){
			flag=false ;
			break;
		}
	}
	if(flag)
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				if(j)cout<<" ";
				if(A[i][j]==INF) cout<<"INF";
				else cout<<A[i][j];
			}
			cout<<endl;
		}
	else cout<<"NEGATIVE CYCLE"<<endl;
	return 0;
} 
