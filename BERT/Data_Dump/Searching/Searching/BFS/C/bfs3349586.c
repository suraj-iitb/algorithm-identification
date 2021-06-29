#include<stdio.h>
#define N 100
#define INF 1000000

void BFS(int );
void enqueue(int);
int dequeue(void);

int n,M[N][N];
int d[N];

int q[2*N];
int head = 1,tail=1;
int i,j;

int main()
{
  int u,k,v;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      M[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u=u-1; //0オリジンへ変換
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v=v-1; //0オリジンへ変換
      M[u][v] = 1; // 辺作成
    }
  }
  BFS(0);
  return 0;
}

void BFS(int s){
  int u,v;
  
  enqueue(s);
  for(i=0;i<n;i++) d[i]=INF;
  d[s]=0;
  while(head!=tail){//空ではないとき
    u=dequeue();
    for(v=0;v<n;v++){
      if(M[u][v]==0) continue;
      if(d[v]!=INF) continue;
      d[v]=d[u]+1;
      enqueue(v);
    }
  }
  for(i=0;i<n;i++){
    if(d[i]==INF) printf("%d %d\n",i+1,-1);
    else printf("%d %d\n",i+1,d[i]);
  }
}

void enqueue(int u){
  q[tail++]=u;
}

int dequeue(void){
  return q[head++];
}

