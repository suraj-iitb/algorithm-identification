#include<stdio.h>
int M[101][101];
int d[101];
int f[101];
int n,t=0;

void search(s){
    int i;

    d[s]=++t;
    for(i=1;i<=n;i++){
	if(M[s][i]==0) continue;
	if(d[i]>0) continue;

	search(i);
    }
    f[s]=++t;
}

int main(void){
    int u,k,v;
    int i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d%d",&u,&k);
	for(j=0;j<k;j++){
	    scanf("%d",&v);
	    M[u][v]=1;
	}
    }

/*
    for(i=1;i<=n;i++){
	for(j=1;j<=n;j++){
	    printf("%d",M[i][j]);
	}
	printf("\n");
    }
*/
    for(i=1;i<=n;i++){
	if(d[i]==0) search(i);
    }

    for(i=1;i<=n;i++){
	printf("%d %d %d\n",i,d[i],f[i]);
    }

    return 0;
}
