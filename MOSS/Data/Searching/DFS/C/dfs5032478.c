#include <stdio.h>
#include <stdlib.h>

void DFS(int *v,int *ans,int j,int k,int n);

int count;
int ans2[100]={0};

int main(void){
	
	int c,i,j,k,u,n;
	
	int path[100]={0};
	int *v=NULL;
	int ans[100]={0};

	
	scanf("%d",&n);
	
	v=(int*)malloc(sizeof(int)*n*n);
	
	c=0;
	
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
	
	count=1;
	
	for(i=0;i<n;i++){
		if(ans2[i]==0){
			DFS(v,ans,i,0,n);
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d %d %d\n",i+1,ans[i],ans2[i]);
	}
	
	free(v);
	
	return 0;
}

void DFS(int *v,int *ans,int j,int k,int n){
	int l;
	
	if(ans[j]!=0 && ans[j] < count){
		return;
	}
	else if(ans2[j]==0){
		ans[j]=count;
	}
	else{
		return;
	}

	++count;
	++k;
	for(l=0;l<n;l++){
		if(v[j*n+l]!=0 && ans2[j]==0 && j!=l){
			DFS(v,ans,l,k,n);
		}
	}
	ans2[j]=count;
	++count;
	
}

