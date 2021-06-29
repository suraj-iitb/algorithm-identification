#include <stdio.h>
#define N 105
#define BLACK -2
#define WHITE 1
#define GRAY 7

typedef struct {
  int color, discover, finish, id;  
}Record;
 
void dfs();
void Visit(int);
void push(int);
void pop();

int adj[N][N], stack[N];
int size, n, time;
Record data[N];

int main () {
  int m, i, j, k, l;

  scanf("%d",&n);

  for(i = 1 ; i <= n ; i++) {
    scanf("%d %d",&l,&m);
    data[l].id = l;
    for(j = 1 ; j <= m ; j++) {
      scanf("%d",&k);
      
      adj[l][k] = 1;
    }
  }
  
  

  dfs();


  for(i = 1 ; i <= n ; i++) {
    printf("%d %d %d\n",data[i].id,data[i].discover,data[i].finish);
  }

  return 0;
}


void dfs() {
  int i;

  for(i = 1 ; i <= n ; i++) data[i].color = WHITE;
  time = 0;

  for(i = 1 ; i <= n ; i++) {
    if(data[i].color == WHITE) Visit(i);
  }
}


void Visit(int x) {
  int u, v, i;
  push(x);
  data[x].color = GRAY;
  data[x].discover = ++time;

  while(size > 0) {
    i = 1;
    u = stack[size-1];
    v = -1;
    while(i <= n){
      if(adj[u][i] == 1 && data[i].color == WHITE) {
	v = i;
	break;
      }
      i++;
    }
    

    if(v != -1) {
      if(data[v].color == WHITE) {
	push(v);
	data[v].color = GRAY;
	data[v].discover = ++time;
      }
    }

    else {
     
      pop();
      data[u].color = BLACK;
      data[u].finish = ++time;
    }
    
  }
  
}






void push(int m) {
  
  stack[size] = m;
  size++;

}

void pop() {
  //size == 0 -> error

  stack[size] = 0;
  size--;
  //return data;
}

