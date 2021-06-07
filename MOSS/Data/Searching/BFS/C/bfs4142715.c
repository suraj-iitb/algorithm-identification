#include<stdio.h>
#define MAX 1000
static int INFTY = (1<<21);

int M[MAX][MAX],d[MAX],f[MAX],Q[MAX*2];
int color[MAX];
int head,tail,n;

void initialize(){
  head = tail = 1;
}

void enqueue(int x){
  Q[tail++] = x;
}

int empty(){
  return head == tail;
}

int dequeue(){
  int x = Q[head++];
  return x;
}

void bfs(int s){
  int i,u,v;
  
  initialize();
  enqueue(s);
  for(i = 0;i < n;i++ ){
    d[i] = INFTY;
  }
  d[s] = 0;
  
  while(!empty()){
    u = dequeue();
    
    for(v = 0;v < n;v++){
      if(M[u][v] == 0)continue;
      if(d[v] != INFTY)continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
  for(i = 0;i < n;i++){
    printf("%d %d\n", i+1,((d[i]==INFTY)?(-1):d[i]));
  }
}

int main(){
  int i,j,a,b,c;
  
  scanf("%d",&n);

  for(i = 0;i <n;i++){
    for(j = 0;j <n;j++)M[i][j] = 0;
  }
  
  for(i = 0;i < n;i++){
    scanf("%d %d",&a,&b);
    a--;
    
    for(j = 0;j < b;j++){
      scanf("%d",&c);
      c--;
      M[a][c] = 1;
    }
    
  }
  
  bfs(0);

  return 0;
}

