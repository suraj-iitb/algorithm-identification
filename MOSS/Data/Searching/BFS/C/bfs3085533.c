#include<stdio.h>

#define max 100
#define INF 1e9

int head,tail,que[max];

void push(int);
int pop(void);
int Empty(void);

int main(){
  int u,num,k,v,i,j,dist[max];
  int data[max][max];
  scanf("%d",&num);

  for(i = 0;i < num;i++){
    for(j = 0;j < num;j++){
      data[i][j] = 0;
    }
    que[i] = -1;
    dist[i] = INF;
  }


for(i = 0;i < num;i++){
  scanf("%d%d",&u,&k);
  u--;
  for(j = 0;j < k;j++){
    scanf("%d",&v);
    v--;
    data[u][v] = 1;
  }
}

head = tail = 0;
dist[0] = 0;
push(0);

while(!Empty()){
  int v = pop();
  for(i = 0;i < num;i++){
    if(data[v][i] == 0){
      continue;
    }
    if(dist[v] + 1 < dist[i]){
      dist[i] = dist[v] + 1;
      push(i);
    }
  }
}

 for(i = 0;i < num;i++){
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

int Empty(){
  return (head == tail);
}

