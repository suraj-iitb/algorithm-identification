#include<stdio.h>
#define N 101

int b[N],d[N],f[N],A[N][N],n,t=1;

void vis(int u){
	int a; 
	d[u]=t++;
	b[u]=1;
	for(a=0;a<n;a++){
		if(A[u][a]==1&&d[a]==0){ 
			vis(a);
		}
	}   
	f[u]=t++;  
}

int main(){
	int a,c,e,i,j;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		scanf("%d%d",&c,&a);
		for(j=0;j<a;j++){
			scanf("%d",&e);
			A[c-1][e-1]=1;
		}
	}
	for(i=0;i<n;i++){
		if(d[i]==0){
			vis(i);
		}
	}
	for(i=0;i<n;i++){
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
	return 0;
}

