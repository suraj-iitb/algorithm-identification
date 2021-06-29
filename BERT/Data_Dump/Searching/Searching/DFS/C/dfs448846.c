#include<stdio.h>
#define MAX 102
#define WHITE 0
#define BLACK 1
#define GRAY 2


void init();
void DFSvisit(int);

int color[MAX];
int n, time = 0;
int d[MAX],f[MAX],edge[MAX],num[MAX][MAX],G[MAX][MAX];

void init(){

  int i,j;

  for(i = 0; i <= n; i++){
      color[i] = WHITE;
    }
  
}

void depthFirstSearch(){
  int i;
  for(i = 1; i <= n; i++){
    if(color[i] == WHITE) DFSvisit(i);
  }
}

void DFSvisit(int u){
  int i,j;
  //  printf("%d\n",u);
  color[u] = GRAY;
  time += 1;
  d[u] = time;

  /*  for(i = 1; i <= n; i++){
    if(color[i] == WHITE && edge[i] != 0){ 
      for(j = 0; j < n; j++){
	if(G[i][j] == 10) {
	  DFSvisit(j);
	}
      }
    }
  */
  for(j = 0; j < n; j++){
    if(G[u][j] == 10) {
      if(color[j+1] == WHITE ){ 
	DFSvisit(j+1);	 
      }
    }
  }


  color[u] = BLACK;

  time = time + 1;
  f[u] = time;


}


int main(){

  int i,j,k = 0,vertex,number;

  scanf("%d\n",&n);
  init();

  for(i = 1; i <= n; i++){
    scanf("%d %d",&vertex,&edge[i]);
    for(j = 1; j <= edge[i]; j++){
      scanf("%d",&number);
      G[vertex][number-1] = 10;
    }
    scanf("\n");
  }
  
/*for(i = 1; i <= n; i++){
    for(j = 0; j < n; j++){
      if(j == n-1){     
    printf("%d\n", G[i][j]);
      } else {
    printf("%d ", G[i][j]);
      }
    }
  }
*/

 depthFirstSearch();
  
  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }
  
  return 0;


}
