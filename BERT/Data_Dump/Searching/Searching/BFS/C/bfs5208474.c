#include<stdio.h>
#define MAX 10000000
#define MIN 1

int adj[101][101],d[101],n;

void exe(int now){
	int Q[100000],front,tail, i;
	front=tail=0;

	Q[tail]=now;	++tail;


	while(front!=tail){
		now=Q[front];	++front;
		for(i=1;i<=n;i++){
			if(adj[now][i]){
				if(d[i]>=0)continue;

				Q[tail]=i;	++tail;
				d[i]=d[now]+1;
			}
		}
	}
}

int main(){
	int i,j,u,k,v,p,q;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&u,&k);
		d[u]=-1;
		for(j=0;j<k;j++){
			scanf("%d",&v);
			adj[u][v]=1;
      p++;
		}
	}
	d[1]=0;

	exe(1);
	for(i=1;i<=n;i++){
		printf("%d %d\n",i,d[i]);
	}

	return 0;
}


