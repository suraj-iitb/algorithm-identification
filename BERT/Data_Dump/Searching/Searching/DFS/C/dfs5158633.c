#include<stdio.h>
#define M 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int a, R[M][M];
int color[M],g[M],f[M],tt;

void dfs_visit(int);

void dfs();

int main(){
  int c,d,l,i,j;
  scanf("%d", &a);
  for(i=0;i<a;i++){
    for(j=0;j<a;j++){
      R[i][j]=0;
    }
  }
  for(i=0;i<a;i++){
    scanf("%d %d",&c,&l);
    c--;
    for(j=0;j<l;j++){
      scanf("%d",&d);
      d--;
      R[c][d]=1;
    }
  }
  dfs();
  return 0;
}
void dfs_visit(int c){
  int d;
  color[c]=GRAY;
  g[c]=++tt;
  for(d=0;d<a;d++){
    if(R[c][d]==0){
      continue;
    }
    if(color[d]==WHITE){
      dfs_visit(d);
    }
  }
  color[c]=BLACK;
  f[c]=++tt;
}

void dfs(){
int c;
for(c=0;c<a;c++){
   color[c]=WHITE;
 }
 tt=0;

 for(c=0;c<a;c++){
   if(color[c]==WHITE){
     dfs_visit(c);
   }
 }
 for(c=0;c<a;c++){
   printf("%d %d %d\n",c+1,g[c],f[c]);
 }
}
