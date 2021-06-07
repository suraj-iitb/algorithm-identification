#include<stdio.h>
#define M 102

int Ad[M][M];
int d[M];
int Q[M];
char color[M];
void enqueue(int);
int dequeue(void);
int n,head=0,tail=0;

int main(){

  int i,j,m,u,k;

  scanf("%d",&n);

  for(i=1;i<M;i++){
    Q[i]=0;
    for(j=1;j<M;j++){
      Ad[i][j]=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&u,&k);
    color[i]='W';
    d[i]=-1;
    if(k!=0){for(j=1;j<=k;j++){
      scanf("%d",&Ad[u][j]);
      }
    }
  }
     
  color[1]='G';
  d[1]=0;
  enqueue(1);

  while(head!=tail){
    u = dequeue();
    m = 1;
    while(Ad[u][m]!=0){
      if(color[Ad[u][m]]=='W'){
	color[Ad[u][m]]='G';
        d[Ad[u][m]]=d[u]+1;
        enqueue(Ad[u][m]);}
        m++;
      }
    color[u]='B';
  }
  
  for(i=1;i<=n;i++){
    printf("%d %d\n",i,d[i]);
  }
 
  return 0;
}


void enqueue(int y){
  Q[tail]= y;
  if(tail+1==n-1) tail=0;
  else tail++;
}

int dequeue(void){
  int x;
  x = Q[head];
  if(head+1==n-1) head=0;
  else head++;

  return x;
}
