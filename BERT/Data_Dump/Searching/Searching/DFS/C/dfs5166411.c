#include <stdio.h>
#define NMAX 101
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct{
  int id;
  int d;
  int f;
  int color;
  int num_next;
  int p;
  int next[NMAX];
}vertex;

int n;
int time = 0;
vertex V[NMAX];

void input(void){
  int i, j;
  
  for(i = 1; i <= n; i++) {
    scanf("%d%d", &(V[i].id), &(V[i].num_next));

    for(j = 1; j <= V[i].num_next; j++){
      scanf("%d", &(V[i].next[j]));
      V[V[i].next[j]].p = V[i].id;
    }
  }
  
}

void output(void){
  int i;
  for(i = 1; i <= n; i++)
    printf("%d %d %d\n", V[i].id, V[i].d, V[i].f);
}

void visit(int id){
    int i;    
    
    V[id].d = ++time;
    V[id].color = GRAY;
        
    for(i = 1; i <= V[id].num_next; i++)
        if(V[V[id].next[i]].color == WHITE)
            visit(V[id].next[i]);
    
    V[id].f = ++time;
    V[id].color = BLACK;
    
}

void DFS(void){
    int i;
    for(i = 1; i <= n; i++)
        if(V[i].color == WHITE)
            visit(i);
    
}

int main(){
  int i, j;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
      V[i].p = NIL;
      V[i].d = NIL;
      V[i].f = NIL;
      V[i].color = WHITE;
    for(j = 1; j <= n; j++) {
      V[i].next[j] = NIL;
    }
  }
  
  input();
  DFS();
  output();
  
  return 0;
}


