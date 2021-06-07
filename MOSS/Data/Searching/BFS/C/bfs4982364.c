#include<stdio.h>
int n;
int M[102][102]={0};
int visited[102]={0};
int Q[102],head=0,tail=0;
int dequeue(){
	head++;
	head=head%102;
	return Q[head-1];
}
void enqueue(int i){
	Q[tail]=i;
	tail++;
	tail=tail%102;
	return;
}
int EmptyQueue(){
	if(head==tail)
	return 1;
	return 0; 
}
void bfs(int i,int d[]){
	enqueue(i);
	d[i]=0;
	visited[i]=1;
	int j,k;
	while(EmptyQueue()==0){
		i=dequeue(); 
		for(j=1;j<=n;j++){
			if(M[i][j]&&(!visited[j])){
				visited[j]=1;
				d[j]=d[i]+1;
				enqueue(j);
			}
		}
	}
	return;
}
int main(){
	scanf("%d",&n);
	int i,j,u,k,v;
	int d[n+1];
	for(i=1;i<=n;i++){
		d[i]=-1;
	} 
	for(i=1;i<=n;i++){
		scanf("%d%d",&u,&k);
		for(j=1;j<=k;j++){
			scanf("%d",&v);
			M[u][v]=1;
		}
	}
	bfs(1,d);
	for(i=1;i<=n;i++){
		printf("%d %d\n",i,d[i]);
	}
	return 0;
} 
