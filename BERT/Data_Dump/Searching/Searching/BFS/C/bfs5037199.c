#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct{
	int N;
	int *k;
	int **G;
}DATA;

void frac(DATA data,int *x,int *d,int now){
	int *c=(int*)malloc(sizeof(int)*data.k[now]);
	int node;
	for(int i=0;i<(data.k[now]);i++){
		c[i]=0;
		node=data.G[now][i];
		if(x[node]==0){//未踏
			x[node]=1;
			d[node]=(d[now]+1);
			c[i]=1;
		}else{
			if((d[now]+1)<d[node]){//更新
				d[node]=(d[now]+1);
				c[i]=1;
			}
		}
	}

	for(int i=0;i<data.k[now];i++){
		if(c[i]==1){
			frac(data,x,d,data.G[now][i]);
		}
	}
	
}

void calc(DATA data){
	int N=data.N;

	int *x=(int*)malloc(sizeof(int*)*(N+1));
	int *d=(int*)malloc(sizeof(int*)*(N+1));
	for(int i=0;i<(N+1);i++){
		x[i]=0;
		d[i]=-1;
	}

	x[1]=1;
	d[1]=0;
	
	frac(data,x,d,1);


	for(int i=1;i<(N+1);i++){
		printf("%d %d\n",i,d[i]);
	}

}

int main(void){
	DATA data;
	int u;

	scanf("%d",&data.N);
	
	data.k=(int*)malloc(sizeof(int)*(data.N+1));
	data.G=(int**)malloc(sizeof(int*)*(data.N+1));
	for(int i=0;i<data.N;i++){
		scanf("%d",&u);
		scanf("%d",&data.k[u]);
		data.G[u]=(int*)malloc(sizeof(int)*data.k[u]);
		for(int j=0;j<data.k[u];j++){
			scanf("%d",&data.G[u][j]);
		}
	}

	calc(data);

	return 0;
}
