#include<stdio.h>
#define WHITE 0    //non-visited
#define GRAY 1     //visited
#define BLACK 2    //finished
#define N 101
#define NIL 100000

typedef struct{
  int id;
  int k;
  int v[N];
  int color;
}V;

int n=0, head=0, tail=0;
int d[N],Q[N];
V S[N];

void Enqueue(int);
int Dequeue(void);

void BFS(int s){
  int i,j,v;
  for(i=1 ; i<=n ; i++) {
    S[i].color = WHITE;
    d[i] = NIL;
  }
  S[s].color = GRAY;
  d[s] = 0;
  
  Enqueue(s);
  
  while(head != tail){
    i = Dequeue();
    for(j=1 ; j<=S[i].k ; j++){
      v = S[i].v[j];
      if(S[v].color == WHITE){
	S[v].color = GRAY;
	d[v] = d[i]+1;
	Enqueue(v);
      }
    }
      S[i].color = BLACK;
  }
}

  /*void DFS_Visit(int u){
  color[u] = GRAY;
  d[u] = ++time;
  int i;
  for(i=1 ; i<=n ; n++) if(color[i] == WHITE) DFS_Visit(i);
  color[u] = BLACK;
  f[u] = ++time;
  }*/

  void Enqueue(int x){
    Q[tail] = x;
    tail++;
  }

  int Dequeue(){
    int x = Q[head];
    head++;
    return x;
  }

int main(){
  int i,j;

  scanf("%d",&n);

  for(i=1 ; i<=n ; i++){
    scanf("%d%d",&S[i].id,&S[i].k);
    for(j=1 ; j<=S[i].k ; j++){
      scanf("%d",&S[i].v[j]);
    }
  }

  BFS(S[1].id);

  for(i=1 ; i<=n ; i++){
    printf("%d ",S[i].id);
    if(d[i] == NIL) printf("-1\n");
    else printf("%d\n",d[i]);
  }

  return 0;
}
