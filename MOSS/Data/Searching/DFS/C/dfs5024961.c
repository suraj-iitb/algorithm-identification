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

struct LIST{
	int id;
	struct LIST *next;
};

void show(int N,struct LIST *L){
	int *d=(int*)malloc(sizeof(int)*(N+1));
	int *f=(int*)malloc(sizeof(int)*(N+1));
	int count=0;
	for(int i=0;i<(N+1);i++){
		d[i]=0;
		f[i]=0;
	}
	while(L!=NULL){
		if(d[L->id]==0){
			d[L->id]=count;
		}else{
			f[L->id]=count;
		}
		count++;
		L=L->next;
	}

	for(int i=1;i<(N+1);i++){
		printf("%d %d %d\n",i,d[i],f[i]);
	}
}


void add(struct LIST *L,int x){
	struct LIST *add=(struct LIST*)malloc(sizeof(struct LIST));
	add->id=x;
	add->next=NULL;

	while(L->next!=NULL){
		L=L->next;
	}
	
	L->next=add;
}

void frac(DATA data,int *X,int now,struct LIST *d){
	X[now]=1;
	add(d,now);
	for(int i=0;i<data.k[now];i++){
		if(X[data.G[now][i]]==0){
			frac(data,X,data.G[now][i],d);
		}
	}
	add(d,now);
}

void calc(DATA data){
	int N=data.N;
	int *X;
	struct LIST *L;
	int flag=0;

	X=(int*)malloc(sizeof(int)*(N+1));
	for(int i=0;i<(N+1);i++){
		X[i]=0;
	}

	L=(struct LIST*)malloc(sizeof(struct LIST));
	L->id=0;
	L->next=NULL;

	int now=1;

	while(1){
		frac(data,X,now,L);
		flag=0;
		for(int i=1;i<(N+1);i++){
			if(X[i]==0){
				flag=1;
				now=i;
				break;
			}
		}
		if(flag==0){
			break;
		}
	}


	show(N,L);
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
