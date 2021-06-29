#include<stdio.h>
#define MAX 100

int matrix[MAX][MAX];//隣接行列
int d[MAX];//発見時刻
int f[MAX];//終了時刻
int flg[MAX];//ノード訪問の情報
int timecnt=0;

void dfs(int u,int n){
	
	flg[u]=1;
	d[u]=++timecnt;
	
	for(int i=0;i<n;i++){
		if(matrix[u][i] && !flg[i]){/*ノードuから到達可能かつ未訪問*/
			dfs(i,n);
		}
	}
	f[u]=++timecnt;
	
	return;
	
}

int main(){
	int n,i,j;
	int x,y,z;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		flg[i]=0;
		for(j=0;j<n;j++)
			matrix[i][j]=0;
	}
	
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		for(j=0;j<y;j++){
			scanf("%d",&z);
			matrix[x-1][z-1]=1;
		}
	}
	
	for(i=0;i<n;i++)
		if(!flg[i])
			dfs(i,n);
	
	
	for(i=0;i<n;i++)
		printf("%d %d %d\n",i+1,d[i],f[i]);
	
	return 0;
	
}


