#include <stdio.h>
#include <stdio.h>
#define N 101
#define WHITE 0
#define GRAY 1
#define BLACK 2



int A[N][N];
int queue[N];
int head = 0;
int tail = 0;
int color[N];
int far[N];
int n;

void enqueue(int a){
  queue[tail] = a;
  tail = (tail+1)%N;
}

int  dequeue(){
  int b;
  b = queue[head];
  head = (head + 1)%N;
  return b;
}

void BFS(){
  int u,i;
  for(i=2;i<=n;++i){
    color[i] = WHITE;
  }

  color[1] = GRAY;
  far[1] = 0;
  enqueue(1);

  while(head != tail){
    u = dequeue();

    for (i=1;i<=n;++i){
      if(A[u][i] == 1 && color[i] == WHITE){
        color[i] = GRAY;
        far[i] = far[u]+1;
        enqueue(i);
      }
    }
    color[u] = BLACK;
  }


}

int main(){
  int i,j,h,sib;

  for(i=0;i<N;++i){
    for(j=0;j<N;++j) A[i][j] = 0;
    far[i] = -1;
  }

  scanf("%d",&n);

  for(i=1;i<=n;++i){
    scanf("%d%d",&sib,&h);

    for(j=1;j<=h;++j){
      scanf("%d",&sib);
      A[i][sib] = 1;
    }
  }

  BFS();

  for(i=1;i<=n;++i)printf("%d %d\n",i,far[i]);


return 0;

}

