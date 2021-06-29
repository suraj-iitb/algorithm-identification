#include <stdio.h>

#define WHITE 1
#define BLACK 0
#define GRAY -1
#define INF  10000
#define N 250

void bfs(int);
void enqueue(int);
int dequeue(void);

int d[N];
int color[N];
int str[N][N];
int n;
int Q[N];
int count1 = 0;
int count2 = 0;

int main(){

 int i;
 int j;
 int k;
 int num;
 int point;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
  scanf("%d%d",&num,&k);
  for(j=1;j<=k;j++){
  scanf("%d",&point);
  str[num][point] = 1;
    }
   }

   bfs(1);
  
  for(i=1;i<=n;i++){
    if(d[i]==INF) d[i] = -1; 
  printf("%d %d\n",i,d[i]);
   }   

  return 0;
}

void bfs(int s){

  int u;
  int v;
  
  for(u=1;u<=n;u++){
    color[u] = WHITE;
    d[u] = INF;
  }

  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);

  while(1){
    u = dequeue();
  for(v=1;v<=n;v++){
    if(color[v]==WHITE && str[u][v]==1){
       color[v] = GRAY;
       d[v] = d[u] + 1;
       enqueue(v);
    }
   }
  color[u] = BLACK;
  if(count1==count2) break;
  }
}

void enqueue(int s){
  Q[count1] = s; 
  count1++;
}

int dequeue(void){
  int r;
  
  r = Q[count2];
  count2++;
  
  return r;
}
