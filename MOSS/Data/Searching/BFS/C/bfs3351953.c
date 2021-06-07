#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1;
int color[101];
int A[101][101];
int n,dis,head,tail;
int q[101];
int d[101];
void bfs(int);
void enqueue(int);
int dequeue(void);
void print(void);
int main(){
  int i,j,k,id,kn;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&kn);
    for(j=0;j<kn;j++){
      scanf("%d",&k);
      A[id][k]=1;
    }
  }
  bfs(1);
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}
void bfs (int root){
  int i,j,u;
  for(i=1;i<=n;i++){
      d[i]=INF;
  }
      d[root]=0;
      color[root]=GRAY;
      head=1;
      tail=2;
      enqueue(root);
      /* print();*/
      while(head!=tail){
	u=dequeue();
	/*print();*/
	for(i=1;i<=n;i++){
	  if(A[u][i]==1){
	    if(color[i]==WHITE){
	      color[i]=GRAY;
	      d[i]=d[u]+1;
	      enqueue(i);
	      /* print();*/
	    }
	  }
	}
	color[u]=BLACK;
      }
}
void enqueue(int k){
  q[tail]=k;
  tail++;
}
int dequeue(void){
  int k;
  k=q[head];
  head++;
  return k;
}
void print(void){
  int i;
  printf("Q----\n");
  for(i=head;i<tail;i++){
    printf("%d ",q[i]);
  }
  printf("%d\n-----Q\n",q[i]);
}
	    
    

    
  
  
 

