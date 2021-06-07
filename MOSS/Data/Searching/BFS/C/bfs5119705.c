#include<stdio.h>
#define MAX 1000
void enqueue(int);
int dequeue();
int size();
void bfs(int);
 
int A[MAX][MAX];
int b[MAX];
int n;
int Q[MAX];
int head=0,tail=0;

int main(){
  int i,j,x,y,z;
  scanf("%d",&n);
  for(i=0;i<MAX;i++) b[i]=-1;
  for(i=0;i<n;i++){
    scanf("%d",&z);
    scanf("%d",&y);
    for(j=0;j<y;j++){
      scanf("%d",&x);
      A[z-1][x-1]=1;
    } 
  }
  b[0]=0;
  bfs(0);
  while(size()!=0) bfs(dequeue());
  for(i=0;i<n;i++) printf("%d %d\n",i+1,b[i]);  
return 0;
}
void enqueue(int x){
  Q[head]=x;
  head++;
}
int dequeue(){
  tail++;
  return Q[tail-1];
} 
int size(){
  return head-tail;
} 
void bfs(int i){
  int j;
  for(j=0;j<n;j++){
    if(A[i][j]==1 && b[j]==-1){
      b[j]=b[i]+1;
      enqueue(j);
    }
  }
}

