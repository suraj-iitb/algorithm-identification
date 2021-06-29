#include <stdio.h>
#include <stdlib.h>

int G[101][101];
int queue[100];
int queS=0;
int queE=0;
int breadth[101]; //0

int dequeue();
void enqueue();
void bfs(int);
void visit(int); 

main(){
  int i, j, k, l, n, adj;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d%d", &l, &k);
    for(j=0; j<k; j++){
      scanf("%d", &adj);
      G[l][adj] = 1;
    }
  }

  bfs(n);

  for(i=1; i<=n; i++){
    printf("%d %d\n", i, breadth[i]);
  }

  return 0;
}

void enqueue(int data){
  queue[queE] = data;
  queE = (queE + 1)%100;
  //printf("** enqueue(%d), queS:%d, queE:%d **\n", data, queS, queE);
}

int dequeue(){
  int tmp = queue[queS];
  queS = (queS+1)%100;

  //printf("** dequeue()=%d, queS:%d, queE:%d **\n", tmp, queS, queE);
  return tmp;
}

void bfs(int n){
  int i;
  //init
  for(i=1; i<=n; i++) breadth[i]=-1;

  enqueue(1);
  breadth[1]=0;
  while(queS != queE) visit(n);
}

void visit(int n){
  static int qued[101];
  static int depth=0;
  int i, j, p;
  p = dequeue();
  //printf("**visit %d**\n", p);

  
  qued[p] = 1;
  for(i=1; i<=n; i++){
    if(G[p][i]==1 && qued[i]==0){
      qued[i] = 1;
      // printf("** breadth[%d] = breadth[%d]+1 = %d **\n",i, p, breadth[p]+1);
      breadth[i] = breadth[p]+1;
      enqueue(i);
    }
  }
}
