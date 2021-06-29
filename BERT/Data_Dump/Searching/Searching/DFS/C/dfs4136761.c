#include <stdio.h>

#define MAX 100

int n,graph[MAX][MAX];
int aaa[MAX],s[MAX],t[MAX],bb;

void DFSsearch(int);
void DFS();

int main(){
  int i,j,a,b,c;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    for(j=0;j<n;j++){
      graph[i][j];
    }
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    a--;
    for(j=0;j<b;j++){
      scanf("%d",&c);
      c--;
      graph[a][c]=1;
    }
  }
  DFS();
  return 0;
}
void DFSsearch(int a){
  int c;
  aaa[a]=1;
  s[a]=++bb;
  for(c=0;c<n;c++){
    if(graph[a][c]==0)
      continue;
    if(aaa[c]==0){
      DFSsearch(c);
    }
  }
  aaa[a]=2;
  t[a]=++bb;
}
void DFS(){
  int a;
  for(a=0;a<n;a++)
    aaa[a]=0;
  bb=0;
  for(a=0;a<n;a++){
    if(aaa[a]==0)
      DFSsearch(a);
  }
  for(a=0;a<n;a++){
    printf("%d %d %d\n",a+1,s[a],t[a]);
  }
}

