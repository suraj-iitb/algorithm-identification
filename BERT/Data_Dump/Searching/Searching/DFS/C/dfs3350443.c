#include<stdio.h>
#define MAX 100
int adj[MAX+1][MAX+1];
int time=0,n;
int d[MAX+1],f[MAX+1];
void search(int p){
	int i;
	if(d[p]==0){
		time++;
		d[p]=time;
		for(i=1;i<=n;i++){
			if(adj[p][i]==1)search(i);
		}
		time++;
		f[p]=time;
	}
}
int main(void){
	int i,j,u,k,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		d[i]=0;f[i]=0;
		for(j=1;j<=n;j++)adj[i][j]=0;
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			adj[u][v]=1;
		}
	}
	for(i=1;i<=n;i++)search(i);
	for(i=1;i<=n;i++)printf("%d %d %d\n",i,d[i],f[i]);
	return 0;
}


