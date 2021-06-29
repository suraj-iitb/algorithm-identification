#include<stdio.h>
#define N 101
#define NIL -1

void BFS(int); 
void Enqueue(int);
int Dequeue(void);
 
typedef struct{
  int id;
  int k;
  int v[N];
  int h;
}V;
 
int n=0, head=0, tail=0, d[N],Q[N];
V G[N];

int main(){
  int i,j;
  
  scanf("%d",&n);
  
  for(i=1 ; i<=n ; i++){
    scanf("%d%d",&G[i].id,&G[i].k);
    for(j=1 ; j<=G[i].k ; j++){
      scanf("%d",&G[i].v[j]);
    }
  }
  
  BFS(G[1].id);
  
  for(i=1 ; i<=n ; i++){
    printf("%d ",G[i].id);
    if(d[i] == NIL) printf("-1\n");
    else printf("%d\n",d[i]);
  }
  
  return 0;
}
void BFS(int s){
  int i,j,v;
  for(i=1 ; i<=n ; i++) {
    G[i].h = 0;
    d[i] = NIL;
  }
  G[s].h = 1;
  d[s] = 0;
   
  Enqueue(s);
   
  while(head != tail){
    i = Dequeue();
    for(j=1 ; j<=G[i].k ; j++){
      v =G[i].v[j];
      if(G[v].h == 0){
	G[v].h =1;
	d[v] = d[i]+1;
	Enqueue(v);
      }
    }
    G[i].h = 2;
  }
}
void Enqueue(int x){
  Q[tail] = x;
  tail++;
}
 
int Dequeue(){
  int x = Q[head];
  head++;
  return x;
}
