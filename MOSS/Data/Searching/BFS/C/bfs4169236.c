#include<stdio.h>
#include<stdlib.h>
#define M 100
#define A 0
#define B 1
#define C 2

int n;
int T[M][M];
int Alph[M],d[M];
int Q[M],head = 0,tail = 0;

void enqueue(int x){
  Q[tail] = x;
  tail = (tail+1)%M;
}

int dequeue(void){
  int x;
  x = Q[head];
  head = (head+1)%M;
  return x;
}

void bfs(int s){
  int i,u,v;

  for(i = 0 ; i < n ; i++){
    Alph[i] = A;
    d[i] = 1000000;
  }

  Alph[s] = B;
  d[s] = 0;
  enqueue(s);

  while(head != tail){
    u = dequeue();
    for(v = 0; v < n ; v++){
      if(T[u][v] == 1 && Alph[v] == A){
	Alph[v] = B;
	d[v] = d[u]+1;
	enqueue(v);
      }
    }
    Alph[u] = C;
  }

}

int main(){
  int i,j;
  int u,k,v;

  scanf("%d",&n);
  if(n < 1 || n > 100)exit(1);

  for(i = 0 ; i < n ; i++){
    for(j = 0 ;  j < n ; j++){
      T[i][j] = 0;
    }
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j = 0 ; j < k ; j++){
      scanf("%d",&v);
      v--;
      T[u][v] = 1;
    }
  }

  bfs(0);

  for(i = 0; i < n ; i++){
    if(d[i] == 1000000) d[i] = -1;
    printf("%d %d\n",i+1,d[i]);
  }

  return 0;
}

