#include<stdio.h>
#define MAX 100
int queue[MAX];
int head=0;
int tail=0;

void enq(int n){
	queue[tail++]=n;
}

int deq(){
	int n=queue[head++];
	return n;
}

int main(void){
	int adj[MAX+1][MAX+1];
	int d[MAX+1];
	int i,j,n,u,k,v;
	int min;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		d[i]=-1;
		for(j=1;j<=n;j++)adj[i][j]=0;
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			adj[u][v]=1;
		}
	}
	
	enq(1);d[1]=0;
	while(head<tail){
		u=deq();
		for(i=1;i<=n;i++){
			if(adj[u][i]==1 && d[i]==-1){
				enq(i);
				d[i]=d[u]+1;
			}
		}
	}
	
	for(i=1;i<=n;i++)printf("%d %d\n",i,d[i]);
	return 0;
}


