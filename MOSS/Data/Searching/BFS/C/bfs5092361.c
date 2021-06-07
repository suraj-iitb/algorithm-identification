#include<stdio.h>

int M[101][101];
int d[101];//始点から各頂点iまでの最短距離
int c[101],n,Q[101];
int head=0,tail=0;

void enqueue(int x){
  Q[tail++]=x;
}

int  dequeue(){
  return Q[head++];
}

int empty(){
    return head!=tail;
}

void bfs(int s){
  int i;

  //訪問状態
  int g=1;
  int b=2;
  int w=0;

  for(i=1;i<=n;i++){//初期化
    d[i]=-1;
  }
  
  c[s]=g;
  d[s]=0;
  enqueue(s);

  while(empty()){
    int u=dequeue();
    int v;
    for(v=1;v<=n;v++){
      if(M[u][v]==1 && c[v]==w){
        c[v]=g;
        d[v]=d[u]+1;
        enqueue(v);
    }
  }
      c[u]=b;
  }
}




int main(void){
    scanf("%d",&n);

    int i,j;
    int u,k,v;
    for(i=0; i<n; i++){
        for(j=0;j<n;j++){
            M[i][j]=0;
        }
    }

    
    for(i=0;i<n;i++){
        scanf("%d%d",&u,&k);
        //u--;
        for(j=0;j<k;j++){
            scanf("%d",&v);
            //v--;
            M[u][v]=1;
        }
    }
    bfs(1);
    for(i=1;i<=n;i++){
	printf("%d %d\n",i,d[i]);
  }
    return 0;

}
