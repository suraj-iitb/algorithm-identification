#include<stdio.h>
#define SHIRO 0
#define NEZUMI 1
#define KURO 2
#define MAX 100
int n;
int AD[MAX][MAX];
int iro[MAX], d[MAX], f[MAX], t;


void DFS2(int);

void DFS(){
  int i;
  for(i = 0 ; i < n ; i++){
    iro[i] = SHIRO;
  }

  t = 0;

  for(i = 0 ; i < n ; i++){
    if(iro[i] == SHIRO) DFS2(i);
  }

  for(i = 0 ; i < n ; i++){
    printf("%d %d %d\n",i+1, d[i],f[i]);
  }
}





int main(){
  int i, j, s, t, u;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){

    for(j = 0 ; j < n ; j++){

      AD[i][j] = 0;
    }
  }

  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&s,&t);
    s--;
    for(j = 0 ; j < t ; j++){
      scanf("%d",&u);
      u--;
      AD[s][u] = 1;
    }
  }

  DFS();

  return 0;
}



void DFS2(int a){
  int i;

  iro[a] = NEZUMI;
  d[a] = ++t;
  for(i = 0 ; i < n ; i++){
    if(AD[a][i] ==  0) continue;
    if(iro[i] == SHIRO){
      DFS2(i);
    }
  }
  iro[a] = KURO;
  f[a] = ++t;
}

