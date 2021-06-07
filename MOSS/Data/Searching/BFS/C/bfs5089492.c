#include <stdio.h>
#define N 100

int main(void){
	int i,j,n,u,k,v; //グラフを隣接行列で表す部分は 11A.c と同じ
	int head=0,tail=1;
	scanf("%d",&n);
	int A[n][n],Q[n],d[n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){ A[i][j]=0; }
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){ scanf("%d",&v); A[u-1][v-1]=1; }
	}
	Q[0]=0; d[0]=0;
	for(i=1;i<n;i++){ d[i]=-1; }
	while(head!=tail){ //キュー(1次元配列)を用いた幅優先探索
		u=Q[head++]; //dequeue
		for(v=0;v<n;v++){
			if(A[u][v]==1 && d[v]==-1){
				d[v]=d[u]+1;
				Q[tail++]=v; //enqueue
			}
		}
	}
	for(u=0;u<n;u++){ printf("%d %d\n",u+1,d[u]); }
	return 0;
}
