#include <stdio.h>

#define N 101

#define WHITE 0
#define GRAY 1
#define BLACK 2

void bfs();
void enq(int);
int deq();

int A[N][N] = {0};
int color[N] = {0};
int d[N];
int stac[N];
int top = 0, tail = 0;
int num ,time;

int main(){
  int inum, jnum, count, i, j;
  
  scanf("%d", &num);
  
  for(i = 1; i <= num; i++){
    scanf("%d %d", &inum, &count);  
    for(j = 1; j <= count; j++){
      scanf("%d", &jnum);
      A[inum][jnum] = 1;
    }
  }
  
  bfs();
  
  for(i = 1; i <= num; i++){
    printf("%d %d\n", i, d[i]);
  }
  
  
  return 0;
}

void bfs(){
  int s = 1, u, i;

  for(i = 1; i <= num; i++){
    d[i] = -1;
  }
  
  color[s] = GRAY;
  d[s] = 0;
  enq(s);
  
  while(top != tail){
    u = deq();
    for(i = 1; i <= num; i++){
      if(A[u][i] == 1 && color[i] ==WHITE){
	color[i] = GRAY;
	d[i] = d[u]+1;
	enq(i);
      }
    }

    color[u] = BLACK;
  }
  
}

void enq(int num){
  stac[tail] = num;
  tail++;
}

int deq(){
  if(top == tail){
    return -1;
  }
  else{
    top++;
    return stac[top-1];
  }
}

