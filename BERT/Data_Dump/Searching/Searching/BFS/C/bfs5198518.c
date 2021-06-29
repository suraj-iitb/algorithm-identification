#include<stdio.h>

#define MAX 100
#define INF 10000000
#define W 0
#define G 1
#define B 2

typedef struct{

  int data[MAX];
  int head,tail;

}queue;

queue Q;

void bfs(int);

int dequeue();

void enqueue(int);


int A[MAX][MAX];
int D[MAX]={INF};
int color[MAX] = {W};
int n;

int main(){
  int i,j,x,y,z;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d %d",&x,&y);

    for(j=0;j<y;j++){

      scanf("%d",&z);

      A[x-1][z-1]=1;
    }
  }

  for(i=0;i<n;i++) D[i]=INF;

  bfs(0);

 for(i=0;i<n;i++){

    if(D[i]==INF){

      printf("%d %d\n",i+1,-1);
    }
      else printf("%d %d\n",i+1,D[i]);
  }

  return 0;
}

void bfs(int s){

  int v,u;

  D[s]=0;
  color[s]=G;
  Q.head=Q.tail=0;

  enqueue(s);

  while(Q.tail < n){

    u=dequeue();

    if(u==INF) break;

    for(v=0;v<n;v++)
      {
 if(A[u][v]==0) continue;

        if(color[v]==W)
        {
        D[v]=D[u]+1;

        color[v]=G;

        enqueue(v);
      }
    }
    color[u]=B;
  }
}



int dequeue(){
  int s;

  if(Q.head==Q.tail) return INF;

  s=Q.data[Q.head];

 Q.head++;

  return s;
}

void enqueue(int s){

  if(Q.tail>=n) return;

  Q.data[Q.tail] = s;

  Q.tail++;
}

