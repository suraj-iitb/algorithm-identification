#include<stdio.h>
#define N 100
#define W 0
#define T 2
#define UN 1

int n,S[N][N];
int c[N],d[N],f[N],ts;

void visit(int u){
  int v;
  c[u]= UN;
  d[u]= ++ts; //fast contact
  for(v=0;v<n;v++){
    if(S[u][v]==0)continue;
    if(c[v]==W){
      visit(v);
    }
  }
  c[u]=T;
  f[u]=++ts;
}

void dfs(){
  int s;
  int i;
  for(s=0;s<n;s++){
    c[s]=W;
  }
    ts =0;

    for(s=0;s<n;s++){
      if(c[s]==W)visit(s);
    }

}

int main(){

  int i,j,x,y,c;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      S[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&y,&c);
    y--;
    for(j=0;j<c;j++){
      scanf("%d",&x);
      x--;
      S[y][x]=1;
    }
  }

dfs();
for(i=0;i<n;i++){
  printf("%d %d %d\n",i+1,d[i],f[i]);
}

  return 0;
}
