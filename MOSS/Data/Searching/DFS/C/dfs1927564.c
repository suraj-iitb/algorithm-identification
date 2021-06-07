#include <stdio.h>
#define N 101
void Search(int);
 
int num,G[N][N],d[N],cnt=0,k=0;
int f[N] = {0};
	 
	  
int main(void){
	int i,j,k,l,u,a,t;
	
	for(i = 0;i < num;i++){
		d[i] = 0;
	}
		
	scanf("%d",&num);
	
	for(i = 0;i <= num;i++){
		for(j = 0;j <= num;j++){
			G[i][j] = 0;
		}
	}
	
	for(i = 0;i < num;i++){
		scanf("%d %d ",&k,&u);
		for(j = 0;j < u;j++){
			scanf("%d",&a);
			G[k - 1][a - 1] = 1;
		}
	}
	
	for(i = 0;i < num;i++){
		if(d[i] == 0)
		Search (i);
	}
	
	for(i = 0;i < num;i++){
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
	
	return 0;
}
	 
	 
void Search(int u){
	int i,j,v;
	cnt++;
	d[u] = cnt;
	
	for(v = 0;v < num;v++){
		if(G[u][v] == 1 && d[v] == 0 ){
			Search(v);
		}
	}
	cnt++;
	f[u] = cnt;
}
