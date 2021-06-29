#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int A[N][N],S[N],d[N],f[N],color[N];

int time,n;

void visit(int a){
  int i;
  
  color[a]=GRAY;
  d[a]=++time;
  for(i=0;i<n;i++){
    if(A[a][i]==0) continue;
    if(color[i]==WHITE) visit(i);
  }

  color[a]=BLACK;
  f[a]=++time;
}


int main(){
  int a,b,c,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&a);
    scanf("%d",&c);
    a--;
    
    for(j=0;j<c;j++){
      scanf("%d",&b);
      b--;
      A[a][b]=1;
    }
  }
  
  for(i=0;i<n;i++){
    color[i]=WHITE;
  }

  time=0;

  for(i=0;i<n;i++){
    if(color[i]==WHITE) visit(i);
  }


  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }

  return 0;
}
