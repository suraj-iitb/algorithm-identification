#include<stdio.h>
#include<stdlib.h>
#define Max 101


int n;
int G[Max][Max];
char color[Max];
int d[Max];
int f[Max];
int time=0;

void visit(int );
void DFS(void );

int main(){
  int i,j;
  int id,num,adj;


  scanf("%d",&n);
  for(i=1 ; i<=n ; i++){
    for(j=1 ; j<=n ; j++) G[i][j] = 0;
  }

  for(i=1 ; i<=n ; i++){
    scanf("%d",&id);
    scanf("%d",&num);
    for(j=0 ; j<num ; j++){
      scanf("%d",&adj);
      G[id][adj] = 1;
    }  
  }

  DFS();
    
  for(i=1 ; i<=n ; i++){
    printf("%d ",i);
    printf("%d ",d[i]);
    printf("%d\n",f[i]);
  }
  return 0;
}

void DFS(void){
  int i;
  for(i=1 ; i<=n ; i++){
    color[i] = 'W';
    time = 0;
  }
  for(i=1 ; i<=n ; i++) if(color[i] == 'W') visit(i);
}

void visit(int u){
  int i;
  color[u] = 'G';
  d[u] = ++time;
  for(i=1 ; i<=n ; i++) if(color[i] == 'W' && G[u][i]) visit(i);
  color[u] = 'B';
  f[u] = ++time;
}
