#include<stdio.h>

#define max 100
#define INF 1e9

int head,tail,que[max];

void push(int);
int pop(void);
int isEmpty(void);

int main(){
  int u,n,k,v,i,j,dist[max];
  int G[max][max];
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      G[i][j] = 0;
    }
    que[i] = -1;
    dist[i] = INF;
  }


for(i = 0;i < n;i++){
  scanf("%d%d",&u,&k);
  u--;
  for(j = 0;j < k;j++){
    scanf("%d",&v);
    v--;
    G[u][v] = 1;
  }
}

head = tail = 0;
dist[0] = 0;
push(0);

while(!isEmpty()){
  int v = pop();
  for(i = 0;i < n;i++){
    if(G[v][i] == 0){
      continue;
    }
    if(dist[v] + 1 < dist[i]){
      dist[i] = dist[v] + 1;
      push(i);
    }
  }
}

 for(i = 0;i < n;i++){
   printf("%d %d\n",i + 1,(dist[i] == INF ? -1 : dist[i]));
 }
 return 0;
}

void push(int x){
  que[tail % max] = x;
  tail++;
}

int pop(){
  int res = que[head % max];
  que[head % max] = -1;
  head++;
  return res;
}

int isEmpty(){
  return (head == tail);
}

