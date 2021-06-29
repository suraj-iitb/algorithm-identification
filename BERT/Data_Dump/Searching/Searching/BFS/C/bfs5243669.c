#include<stdio.h>
#define N 101
#define INF (1<<30)



int G[N][N];
int d[N],vis[N];
int n;
int tt=0;
int A[N];
int head,tail;


void enqueue(int key){
  A[tail]=key;
  tail=(tail+1)%N;
}

int dequeue(){
  int res=A[head];
  head=(head+1)%N;
  return res;
}






void bfs(){

  int pos=1;
  int i;

  vis[pos]=1;
  d[pos]=0;
  enqueue(pos);




  while(head!=tail){
    pos=dequeue();

    for(i=1;i<=n;i++){
      if(vis[i]|| G[pos][i]==-1)continue;
      enqueue(i);
      vis[i]=1;
      d[i]=d[pos]+1;
    }
  }
}



int main(){


  int i,j;
  int u,k,v,c;

  scanf("%d",&n);
  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      G[i][j]=-1;
    }
    vis[i]=0;
    d[i]=-1;
  }


  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      G[u][v]=1;
    }
  }


  bfs();

  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }













  return 0;
}

