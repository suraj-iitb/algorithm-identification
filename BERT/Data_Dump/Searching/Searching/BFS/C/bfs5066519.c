#include<stdio.h>

int adj[101][101]={0};
int Q[101],d[101]={0},status[101];
int n,top=0,tail=0;

void push(int x){
	Q[top]=x;
	top++;
}

int pop(){
	int q=Q[tail];
	tail++;
	return q;
}

void bfs(int x){
	int i,u;
	push(x);
	status[x]=0;
	
	while(top!=tail){
		u=pop();
		
		for(i=1;i<n+1;i++){
			if(adj[u][i]==1 && status[i]==-1){
				status[i]=0;
				push(i);
				d[i]=d[u]+1;
			}
		}
		
		status[u]=1;
	}
}

int main(void){
	int i,j,u,k,v;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		
		for(j=0;j<k;j++){
			scanf("%d",&v);
			adj[u][v]=1;
		}
	}
	
	for(i=1;i<n+1;i++){
		status[i]=-1;
	}
	
	for(i=1;i<n+1;i++){
		d[i]=0;
		
		if(status[i]==-1){
			bfs(i);
		}
		
		for(i=2;i<n+1;i++){
			if(d[i]==0){
				d[i]=-1;
			}
		}
	}
	
	for(i=1;i<n+1;i++){
		printf("%d %d\n",i,d[i]);
	}
	
	return 0;
}
