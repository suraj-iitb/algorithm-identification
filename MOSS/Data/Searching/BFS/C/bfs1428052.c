#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BRACK 2

int **matrix;
int *color;
int *dist;

int n;
int time;

int *queue;
int head;
int tail;

void enqueue(int);
int dequeue(void);
void bfs(void);


int main(){
  int i,j,u,k,v;

  scanf("%d",&n);

  queue = malloc((n+1) * sizeof(int));
  color = malloc((n+1) * sizeof(int));
  dist = malloc((n+1) * sizeof(int));
 
  
  matrix = malloc((n+1) * sizeof(int *));
  for(i=0;i<n+1;i++) matrix[i] = malloc((n+1) * sizeof(int));


  for(i=1;i<n+1;i++){
 dist[i] = -1;
 color[i] =WHITE;
  }
  
  for(i=1;i<n+1;i++)
    for(j=1;j<n+1;j++)
      matrix[i][j] = 0;
  
  
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      matrix[u][v] = 1;
    }
  }


  bfs();
 

  for(i=1;i<n+1;i++) printf("%d %d\n",i,dist[i]);

  for(i=0;i<n+1;i++)
    free(matrix[i]);
  free(matrix);
  free(queue);
  free(dist);
  free(color);

  return 0;
}

void bfs(){
  int u,i;

  head = tail = 0;
  color[1] = GRAY;
  dist[1] = 0;
  enqueue(1);
  
  while(head != tail){
    u = dequeue();
    for(i=1;i<n+1;i++){
      if(matrix[u][i] == 1 && color[i] == WHITE){
	color[i] = GRAY;
	dist[i] = dist[u] + 1;
	enqueue(i);
      }
    }
    color[u] = BRACK;
  }
}

void enqueue(int q){
  
  queue[tail] = q;
  if(++tail == (n+1)) tail = 0;
  
}

int dequeue(){
  int v;
  
  v = queue[head];
  if(++head == (n+1)) head=0;
  return v;

}
