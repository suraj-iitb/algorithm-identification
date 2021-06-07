#include<stdio.h>


#define LIMIT 101

int time=1;
int g[LIMIT][LIMIT];
int d[LIMIT] ;
int f[LIMIT] ;
int n;

void search(int p){
  int i;

  if(d[p]>0)return ;
	d[p]=time;
	time++;

	for(i=1;i<=n;i++){
		if(g[p][i]==1&&d[i]==0){
 			search(i);
		}
	}

	f[p]=time;
	time++;
}

int main(){
	int u,k,v;
  int i;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
 		while(k--){
			scanf("%d",&v);
			g[u][v]=1;
		}
	}
	for(i=1;i<=n;i++){
		search(i);
	}
	for(i=1;i<=n;i++)printf("%d %d %d\n",i,d[i],f[i]);

  return 0;
}

