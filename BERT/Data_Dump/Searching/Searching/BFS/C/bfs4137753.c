#include<stdio.h>
#define N 102
int M[N][N];
int ki[N],o;

void q(int t){
  int Q[1000];
  int head=0,tail=0;
  int i;
  Q[tail]=t;
  ++tail; 
  while(1){
    if(head==tail) break;
    
    t=Q[head];
    ++head;
    for(i=1;i<=o;i++){
      if(M[t][i]==1){
	if(ki[i]>=0)continue;
	Q[tail]=i;
	++tail;
	ki[i]=ki[t]+1;
      }
    }
  }
}

int main(){
  int i,j,k,u,M2;

  scanf("%d",&o);
  for(i=0;i<o;i++){
    for(j=0;j<o;j++){
      M[i][j]=0;
    }
  }
  
  for(i=0;i<o;i++){
    scanf("%d%d",&u,&k);
    ki[u]=-1;
    for(j=0;j<k;j++){
      scanf("%d",&M2);
      M[u][M2]=1;
    }
  }
  
  ki[1]=0;
  q(1);
  for(i=1;i<=o;i++){
    printf("%d %d\n",i,ki[i]);
  }
  return 0;
}


