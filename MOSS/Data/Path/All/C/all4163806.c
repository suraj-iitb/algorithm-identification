//By Vlgd
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
long long d[N][N],INF=(1ll<<32);
void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(d[i][k]==INF) continue;
			for(int j=0;j<n;j++){
				if(d[k][j]==INF) continue;
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j]=(i==j?0:INF); 
	for(int i=0;i<m;i++){
		int u,v;long long w;
		scanf("%d%d%lld",&u,&v,&w);
		d[u][v]=w; 
	}
	floyd();
	bool isn=false;
	for(int i=0;i<n;i++) if(d[i][i]<0){isn=true;break;}
	if(isn) printf("NEGATIVE CYCLE\n");
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(d[i][j]<INF) printf("%d",d[i][j]);
				else printf("INF");
				if(j!=n-1) printf(" ");
				else printf("\n");
			}
		}
	}
}

