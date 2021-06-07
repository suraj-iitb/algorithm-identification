#include<stdio.h>

typedef struct{
  int num;
  int color;/*-1 = gray 0 = non color 1 = black*/
  int mark;
  int d;
  int f;
}Vert;

Vert G[101];

int S[101];

int A[101][101];

int count = 0,s = 0;

void visit(int n,int start){
  int i,j = 0;

  if(S[s] == 0){
      if(G[1].color == 1 && G[start].color == 1) return;
  }

  if(G[start].color == 0){
    G[start].d = ++count;
    G[start].color = -1;
    s++;
    S[s] = start;
  }

  else if(G[start].color == -1){
    for(i = 1;i <= n;i++){
      if(A[start][i] == 1 && G[i].color == 0) j = 1;
    }
    if(j == 0){
      G[start].f = ++count;
      G[start].color = 1;
      s--;
    }
  }

  for(i = 1;i <= n;i++){
    if(A[start][i] == 1 && G[i].color == 0){
      visit(n,i);
    }
  }

  if(s == 0) return;

  for(i = 1;i <= n;i++){
    if(A[S[s]][i] == 1 && G[i].color == 0) j = 1;
  }
  if(j == 0){
    G[S[s]].f = ++count;
    G[S[s]].color = 1;
    s--;
  }
  visit(n,S[s]);
}

void exvert(int n){
  int i;
  for(i = 1;i <= n;i++){
    if(G[i].mark == 0){
      visit(n,i);
    }
  }
}



int main(){
  int n,m,i,j,k,p;

  S[0] = 0;

  scanf("%d",&n);

  for(i = 0;i <= n;i++){
    for(j = 0;j <= n;j++){
      A[i][j] = 0;
      G[i].color = 0;
      G[i].mark = 0;
    }
  }

  G[1].mark = -1;
  G[0].color = 1;

  for(i = 0;i < n;i++){
    scanf("%d",&m);
    scanf("%d",&p);
    for(j = 0;j < p;j++){
      scanf("%d",&k);
      A[m][k] = 1;
      G[k].mark = 1;
    }
  }

  visit(n,1);

  exvert(n);

  for(i = 1;i <= n;i++) printf("%d %d %d\n",i,G[i].d,G[i].f);

  return 0;
}

