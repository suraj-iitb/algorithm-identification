#include<stdio.h>

int N[100],M[100],A[100];
int x[100][100];
int count;

int main(){
	int n;
	scanf("%d",&n);
	int u,k,v;
	count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		x[i][j]=0;
	}
	for(int i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&v);
			x[u-1][v-1]=1;
		}
	}
	for(int i=0;i<n;i++)
	N[i]=0;
	for(int i=0;i<n;i++){
		if(N[i]==0)
		DFS(i,n);
	}
	for(int i=0;i<n;i++)
	printf("%d %d %d\n",i+1,M[i],A[i]);
	
	return 0;
}

    void DFS(int i,int n){
    N[i]=1;
	count++;
	M[i]=count;
	for(int j=0;j<n;j++){
		if(x[i][j]==0)continue;
		if(N[j]==0)
		DFS(j,n);
	}
	N[i]=1;
	count++;
	A[i]=count;
}


