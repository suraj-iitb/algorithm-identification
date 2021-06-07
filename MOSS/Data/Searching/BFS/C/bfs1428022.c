#include <stdio.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK -1

typedef struct {
  int number[MAX];
  int head;
  int tail;
} QUEUE;

int adj[MAX][MAX], d[MAX], color[MAX];
QUEUE Q;

void enqueue(int x){
  Q.number[Q.tail] = x;
  Q.tail++;
  
  if( Q.tail > MAX ) Q.tail = 0;
  
}

int dequeue(void){
  int x;
  
  x = Q.number[Q.head];
  Q.number[Q.head] = 0;
  Q.head++;
  
  return x;
  
}


void BFS(int n){
  int i, j, u;
  
  for( i = 1; i <= n; i++){
    color[i] = WHITE;
    d[i] = -1;
  }
  
  color[1] = GRAY;
  d[1] = 0;
  Q.head = 0;
  Q.tail = 0;
  
  enqueue(1);

  while( Q.head != Q.tail ){
    
    u = dequeue();
    
    // printf("{u} = %d\n", u);
    
    for( j = 1; j <= n; j++){
      if( adj[u][j] == 1 ){
	if( color[j] == WHITE ){
	  color[j] = GRAY;
	  d[j] = d[u] + 1;
	  //printf("d[%d] = %d\n", j, d[j]);
	  enqueue(j);
	}
      }
    }
    
    color[u] = BLACK;
    
  }
  
}


main(){
  int i, j, n, k, u, v;
  
  for( i = 0; i < MAX; i++){
    for( j = 0; j < MAX; j++){
      adj[i][j] = 0;
    }
  }
  
  scanf("%d", &n);
  
  for( i = 1; i <= n; i++){
    scanf("%d%d", &u, &k);
    for( j = 1; j <= k; j++){
      scanf("%d", &v);
      adj[i][v] = 1;
    }
  }
  
  /* 
     for( i = 1; i <= n; i++){
     for( j = 1; j <= n; j++){
     printf("%d ", adj[i][j]);
     }
     printf("\n");
     }
  */
  
  BFS(n);
  
  for( i = 1; i <= n; i++){
    printf("%d %d\n", i, d[i]);
  }
  
  return 0;
  
}
