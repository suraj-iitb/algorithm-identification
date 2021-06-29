#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int h;
int PM[100][100];
int color[100],d[100],f[100],time;

void DFS();
void DFSvisit(int);

int main(){
  int i,j,k,l,m;
  scanf("%d",&h);

  for(i=0;i<h;i++){
    for(j=0;j<h;j++){
      PM[i][j]=0;
    }
  }
  for(i=0;i<h;i++){
    scanf("%d%d",&k,&l);
    k--;
    for(j=0;j<l;j++){
      scanf("%d",&m);
      m--;
      PM[k][m]=1;
    }
  }

  DFS();
  
  return 0;
}
void DFS(){
  int i;
   for(i=0;i<h;i++){
     color[i]=WHITE;
   }

   time=0;
  for(i=0;i<h;i++){
    if( color[i]== WHITE)DFSvisit(i);
  }
  
    for(i=0;i<h;i++){
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}

void DFSvisit(int x){
  int i;

  color[x]=GRAY;
  d[x]=++time;
  for(i=0;i<h;i++){
    if(PM[x][i]==0)continue;
    if(color[i]==WHITE){
      DFSvisit(i);
    }
  }
  color[x]=BLACK;
  f[x]=++time;
}


