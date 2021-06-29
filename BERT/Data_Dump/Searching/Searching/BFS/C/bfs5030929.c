#include <stdio.h>
#include <stdlib.h>

#define N 100

void BFS(int *v,int *ans,int i,int j,int n);
//Breadth_First_Search

int count;

int main(void){
	
	int c,i,j,k,u,n;
	
	int path[N]={0};
	int *v=NULL;
	int ans[N]={0};
	
	scanf("%d",&n);
	
	v=(int*)malloc(sizeof(int)*n*n);
	
	c=0;
	count=1;
	
	for(i=0;i<N;i++){
		ans[i]=-1;
	}
	
	for(i=0;i<n;i++){
		
		scanf("%d",&u);
		
		scanf("%d",&k);
	
		for(j=0;j<n;j++){
			
			if(j<k){
				scanf("%d",&path[j]);
			}
			else{
				path[j]=0;
			}
		}
		
		for(j=0;j<n;j++){
			if(j+1==path[c]){
				v[n*i+j]=1;
				++c;
			}
			else{
				v[n*i+j]=0;
			}
		}
		c=0;
	}

	BFS(v,ans,0,0,n);
	
	for(i=0;i<n;i++){
		printf("%d %d\n",i+1,ans[i]);
	}
	
	free(v);
	
	return 0;
}

void BFS(int *v,int *ans,int i,int j,int n){//i is number of path, j is suffix
	int k;
	
	if(ans[j]==-1 || ans[j] > i){
		ans[j]=i;
	}
	else if(ans[j] < i){
		return;
	}
	else{
		;
	}
	
	++i;
	
	for(k=0;k<n;k++){
		if(v[j*n+k]!=0){
			BFS(v,ans,i,k,n);
		}
		
	}
	
}

