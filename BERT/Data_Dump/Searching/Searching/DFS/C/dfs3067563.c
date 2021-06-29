#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int k;
  int v[100];
  int color; //0=white,1==black
  int dt,ft;
}U;

void visit(int);

U *u;
int t;
int s[101],stop=0;

int main(){
  int n,i,j,id,k,v;
  
  scanf("%d",&n);
  u = malloc(sizeof(U) * (n+1));
  
  for(i = 0; i < n; i++){
    scanf("%d",&id);
    scanf("%d",&u[id].k);
    // u[id].v = malloc(sizeof(int) * k);
    for(j = 0; j < u[id].k; j++){
      scanf("%d",&u[id].v[j]);
    }
    u[id].color = 0;
  }

  for(i = 1; i <= n; i++){
    if(u[i].color == 0)
      visit(i);
  }

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n",i,u[i].dt,u[i].ft);
  }
    
  return 0;
}
  
void visit(int i){
  int p,q;

  u[i].dt = ++t;
  u[i].color = 1;
  for(p = 0; p < u[i].k; p++){
    if(u[u[i].v[p]].color == 0)
      visit(u[i].v[p]);
  }
  u[i].ft = ++t;
}

