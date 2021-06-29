#include <stdio.h>
#include <memory.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100

int queue[N],len[N],col[N],M[N][N];
int n;


void bfs(void){
    int s,top,end,i;
    memset(len,-1,sizeof(len));
    len[0]=0;
    for(top=0,end=1;end != top;){
        s=queue[top];
        top++;
        for(i=0;i<n;i++){
          if(M[s][i] != 0 && col[i] == WHITE){
            queue[end++] = i;
            len[i] = len[s] + 1;
            col[i]=GRAY;
          }
      }
      col[s]=BLACK;
    }
    for(i=0;i<n;i++){
     printf("%d %d\n",i+1,len[i]);
   }
}

int main(){
  int u,k,v,i,o;

  scanf("%d",&n);

  for(i=0;i<n;i++){
   scanf("%d %d",&u,&k);
   u--;
   for(o=0;o<k;o++){
    scanf("%d",&v);
    v--;
    M[u][v]=1;
    }
  }

  col[0]=BLACK;
  bfs();

  return 0;
}

