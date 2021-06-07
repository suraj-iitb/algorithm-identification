#include<stdio.h>

#define MAX 1000
#define N 10000

int graph[MAX][MAX];
int d[MAX];
int n;

int Q[N];
int max=0,min=0;

void enQ(int q){
  Q[max]=q;
  max++;
}

int deQ(){
  min++;
  return Q[min-1];
}

int size(){
  return max-min;
}

void bfs(int i){
  int j;
  for(j=0;j<n;j++){
    if(graph[i][j]==1 && d[j]==-1){
      d[j]=d[i]+1;
      enQ(j);
    }
  }
}

int main(){
  int i,j,a,b,c;

  scanf("%d",&n);

  for(i=0;i<MAX;i++) d[i]=-1;
  for(i=0;i<n;i++){
    scanf("%d",&a);
    scanf("%d",&b);
    for(j=0;j<b;j++){
      scanf("%d",&c);
      graph[a-1][c-1]=1;
    }
  }
  d[0]=0;
  bfs(0);

  while(size()!=0) bfs(deQ());

  for(i=0;i<n;i++) printf("%d %d\n",i+1,d[i]);

  return 0;
}
