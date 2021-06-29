#include<stdio.h>

int w[100],g[100],k[100];
int x[100][100];
int count;

void re(int i,int n){
	int j;
	w[i]=1;
	count++;
	g[i]=count;
	for(j=0;j<n;j++){
		if(x[i][j]==0)continue;
		if(w[j]==0)re(j,n);
	}
	w[i]=1;
	count++;
	k[i]=count;
}

int main(void){
	int n,i,j;
	scanf("%d",&n);
	int y,z,p;
	count=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)x[i][j]=0;
	}
	for(i=0;i<n;i++){
		scanf("%d %d",&y,&z);
		for(j=0;j<z;j++){
			scanf("%d",&p);
			x[y-1][p-1]=1;
		}
	}
	for(i=0;i<n;i++)w[i]=0;
	for(i=0;i<n;i++){
		if(w[i]==0)re(i,n);
	}
	for(i=0;i<n;i++)printf("%d %d %d\n",i+1,g[i],k[i]);
	
	return 0;
}
