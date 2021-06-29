#include<stdio.h>
#define N 501


static const int WH = 0;
static const int GR = 1;
static const int BL = 2;

int num,M[N][N];
int co[N],da[N],fa[N],tta;

void sea(int x){
  int v;
  co[x] =GR;
  tta++;
  da[x]=tta;
  for(v=0;v<num;v++){
    if(M[x][v] == 0){
      continue;
    }
    if(co[v] == WH){
     sea(v);
    }
  }
  co[x] = BL;
  fa[x] = ++tta;
}

void ho(){
  int i,x;
  for(i=0;i<num;i++){
    co[i] = WH;
  }
  tta=0;
  for(x=0;x<num;x++){
    if(co[x] == WH){
      sea(x);
    }
  }
  for(i=0;i<num;i++){
    printf("%d %d %d\n",i+1,da[i],fa[i]);
  }
}

int main(){
  int x,h,w;
  int i,j;

  scanf("%d",&num);

  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      M[i][j]=0;
    }
  }

  for(i=0;i<num;i++){
    scanf("%d %d",&x,&h);
    x--;
    for(j=0;j<h;j++){
      scanf("%d",&w);
      w--;
      M[x][w] =1;
    }
  }
  ho();

  return 0;
}

