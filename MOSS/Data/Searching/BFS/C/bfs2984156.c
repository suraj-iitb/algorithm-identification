#include<stdio.h>
#define N 100

int a[N+1][N+1];
int d[N+1];
int flg[N+1];

typedef struct Que{
	int num[N+1];
	int top;
}Que;

Que Q;

void enqueue(int x){
	Q.num[Q.top++]=x;
	return;
}

int dequeue(){
	int x=Q.num[0];
	for(int i=0;i<Q.top-1;i++)
		Q.num[i]=Q.num[i+1];
	Q.top--;
	return x;
}

void bfs(int u,int n){
	Q.top=0;
	
	enqueue(u);
	d[u]++;
	flg[u]=1;
	
	while(Q.top>0){
		int v=dequeue();
		for(int i=1;i<=n;i++){
			if(a[v][i]==1 && !flg[i]){
				enqueue(i);
				d[i]=d[v]+1;
				flg[i]=1;
			}
		}
	}
	
	return;
	
}

int main(){
	int n,i,j;
	int x,y,z;
	
	scanf("%d",&n);
	
	for(i=0;i<=n;i++){
		d[i]=-1;
		flg[i]=0;
		for(j=0;j<=n;j++){
			a[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		for(j=0;j<y;j++){
			scanf("%d",&z);
			a[x][z]=1;
		}
	}
	
	bfs(1,n);
	
	for(i=1;i<=n;i++)
		printf("%d %d\n",i,d[i]);
	
	return 0;
	
}
