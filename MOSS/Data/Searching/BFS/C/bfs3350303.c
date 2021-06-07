#include <stdio.h>
#define MAX 100
#define INF 1<<21

void bfs(int,int,int *);
void enqueue(int);
int dequeue();

int Ad[MAX][MAX],queue[MAX],head,tail,tas;

int main(){
  int n,i,j,u,k,v,visiter[MAX];
  
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++) Ad[i][j] = 0;
  }

  for(i = 0;i < n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j = 0;j < k;j++){
      scanf("%d",&v);
      Ad[u][--v] = 1;
    }
  }
  bfs(0,n,visiter);

  return 0;
}

void bfs(int i,int n,int * visiter){
  int j,box,l;
  
  enqueue(i);
  for(j = 0;j < n;j++) visiter[j] = INF;
  visiter[i] = 0;
  while(tas != 0){
    box = dequeue();
    for(l = 0;l < n;l++){
      if(Ad[box][l] == 0) continue;
      if(visiter[l] != INF) continue;//INF ga kakikae rarete nai
      visiter[l] = visiter[box] + 1;
      enqueue(l);
    }
  }
  for(j = 0;j < n;j++){
    printf("%d ",j + 1);
    if(visiter[j] != INF) printf("%d\n",visiter[j]);
    else printf("-1\n");
      }
}


void enqueue(int n) {
  tas++;
  //  if(tail <= MAX) return -1;
  queue[tail++] = n;
}

int dequeue() {
  tas--;
  //  if(head >= tail) return -1;
  return queue[head++];
}

