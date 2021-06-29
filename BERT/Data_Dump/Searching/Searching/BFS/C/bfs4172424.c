#include <stdio.h>
#define M 100
#define INFTY 21
int graph_s[M][M];
int comp[M],count[M],out[M];
int head=0,tail=0,n;


void enqueue(int x){
  out[tail]=x;
  if(tail+1==M)tail=0;
  else tail++;
}

int dequeue(){
  int x;
  x=out[head];
  if(head+1==M) head=0;
  else head++;
  return x;
}

 int empty(){
   if(head==tail) return 1;
   else return 0;
 }


void bfs(){
  int comp[M];
  int count[M];
  int i,x;
  for(i=0;i<n;i++){
    comp[i]=0;
    count[i]=INFTY;
  }
  comp[0]=1;
  count[0]=0;
  enqueue(0);

  while(!empty()){
    x=dequeue();
    for(i=0;i<n;i++){
      if(graph_s[x][i] && comp[i]==0){
        comp[i]=1;
        count[i]=count[x]+1;
        enqueue(i);
      }
    }
    comp[x]=2;
  }
  for(i=0;i<n;i++){
    printf("%d ",i+1);
    if(count[i]==INFTY) printf("-1\n");
    else printf("%d\n",count[i]);
  }
}

int main(){
  int i,j,nu,out,near;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      graph_s[i][j]=0;
    }
  } 
  for(i=0;i<n;i++){
    scanf("%d%d",&nu,&out);
    for(j=0;j<out;j++){
      scanf("%d",&near);
      graph_s[nu-1][near-1]=1;
    }
  }

  bfs();

  
  return 0;
}

