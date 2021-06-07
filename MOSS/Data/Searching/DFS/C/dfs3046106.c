#include <stdio.h>
#define N 101

int n,Go[N],Back[N],Link[N],Keep[N][N],Count=1;

void dfs(int x){

	int i;
	Go[x] = Count++;

	for(i = 0; i < Link[x]; i++){
		if(Go[Keep[x][i+1]] == 0){
			dfs(Keep[x][i+1]);
		}
	}
	Back[x] = Count++;
}
  
int main(){

	int i,j,Num;

	scanf("%d",&n);
	for( i = 0; i < n; i++){
		Go[i+1] = Back[i+1] = 0;
		scanf("%d",&Num);
		scanf("%d",&Link[Num]);
		for(j = 0; j < Link[Num]; j++) scanf("%d",&Keep[Num][j+1]);
	}

	for(i = 0; i < n; i++) if(Go[i+1] == 0) dfs(i+1);

	for(i = 0; i < n; i++){
		printf("%d %d %d\n",i+1,Go[i+1],Back[i+1]);
	}

	return 0;
}
