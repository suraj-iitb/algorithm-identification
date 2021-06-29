#include<stdio.h>
#define N 100
#define INF -1

int Q[N], M[N][N], head,tail;
int d[N];   //距離で訪問状態を管理する
int n;
int dequeue();
void enqueue(int q);
int enpty();
void bfs(int);

int main(){
  int a,b,c;
  int i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    a--;
    for(j=0;j<b;j++){
      scanf("%d",&c);
      c--;
      M[a][c] = 1;
    }
  }

  bfs(0);

  return 0;
}


int dequeue(){  //キューからデータを取り出す
  int x=Q[head];
  
  head=(head+1)%N;
  return x;
}

void enqueue(int q){ //キューにデータを入れる
  Q[tail]=q;
  tail=(tail+1)%N;
}


int enpty(){
  if(tail==head)
    return 1;
  else
    return 0;
}

void bfs(int s){
  int i;
  int u,v;
  enqueue(s);

  for(i=0;i<n;i++){
    d[i]=INF;
  }

  d[s]=0;

  while(!enpty()){
    u = dequeue();
    for(v=0;v<n;v++){
      if(M[u][v] == 0)continue;
      if(d[v] != INF)continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }

  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,((d[i] == INF)? -1 : d[i]));
  }
}


