#include <stdio.h>
#define N 100

//各頂点の状態は未探索の0,探索中の1で表す
int n,A[N][N];
int status[N],d[N],f[N],time; //発見時刻 d,完了時刻 f

void dfs(int u){ //再帰によるdfs
	int v;
	status[u]=1;
	d[u]=time++;
	for(v=0;v<n;v++){
		if(A[u][v]==1){
			if(status[v]==0){ dfs(v); } //未探索の頂点を探す
		}
	}
	f[u]=time++;
}

int main(void){
	int i,j,u,k,v; //グラフを隣接行列で表す部分は 11A.c と同じ
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){ A[i][j]=0; }
	}
	for(u=0;u<n;u++){ status[u]=0; }
	time=1; //時刻は1で初期化
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){ scanf("%d",&v); A[u-1][v-1]=1; }
	}
	for(u=0;u<n;u++){ //ここからdfsを開始
		if(status[u]==0){ dfs(u); }
	}
	for(u=0;u<n;u++){ printf("%d %d %d\n",u+1,d[u],f[u]); }
	return 0;
}
