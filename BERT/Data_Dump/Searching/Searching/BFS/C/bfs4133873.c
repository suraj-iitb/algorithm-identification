#include <stdio.h>

#define Q 100

void bfs();
void enqueue(int);
int dequeue();

int head = 0,tail = 0,n;
int q[Q+1],b[Q+1][Q+1],color[Q+1] = {},d[Q+1] = {};

int main(){
  int i,j,id,k,v;
  
  scanf("%d",&n);
  for(i = 1; i < n+1; i++){
    scanf("%d %d",&id,&k);
    for(j = 0;j < k;j++){
      scanf("%d",&v);
      b[id][v] = v;
    }
  }
  
  bfs();
  
  for(i = 1; i < n+1; i++){
    if(i != 1 && d[i] == 0)printf("%d -1\n",i);
    else printf("%d %d\n",i,d[i]);
  }
  return 0;
}

void bfs(){
  int i,u;
  color[1] = -1;
  enqueue(1);
  while(head != tail){
    u = dequeue();
     for(i = 1;i < n+1;i++){
       if(b[u][i] != 0){
      if(color[i] == 0){
	color[i] = -1;
	d[i] = d[u] + 1;
	enqueue(i);
      }
     }
    }
  }
  color[u] = -2;
}

void enqueue(int a){
  int next;
  next = (tail+1)%Q;
  
  if(tail != next){
    q[tail] = a;
    tail = next;
  }
}

int dequeue(){
  int val;
  if(head != tail){
    val = q[head];
    head = (head+1)%Q;
    
  }
  return val;
}

