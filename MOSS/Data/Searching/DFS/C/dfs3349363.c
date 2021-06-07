#include<stdio.h>
#define N 500

static const int A=0;
static const int B=1;
static const int C=2;

int a,T[N][N];
int b[N],c[N],d[N],e;

void X(int x){
  int p;
  b[x]=B;
  e++;
  c[x]=e;
  for(p=0;p<a;p++){
    if(T[x][p]==0){
      continue;
    }
    if(b[p]==A){
      X(p);
    }
  }
  b[x]=C;
  d[x]=++e;
}

void Y(){
  int x,y;
  for(x=0;x<a;x++){
    b[x]=A;
  }
  e=0;
  for(y=0;y<a;y++){
    if(b[y]==A){
      X(y);
    }
  }
    for(x=0;x<a;x++){
      printf("%d %d %d\n",x+1,c[x],d[x]);
    }
  }

int main(){
  int x,y,z,i,j;

  scanf("%d",&a);

  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      T[i][j]=0;
    }
  }

  for(i=0;i<a;i++){
    scanf("%d %d",&x,&y);
    x--;
    for(j=0;j<y;j++){
      scanf("%d",&z);
      z--;
      T[x][z]=1;
    }
  }

  Y();

  return 0;
}

