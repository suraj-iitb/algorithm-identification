#include<stdio.h>
void DFS(void);
void visit(int);
int n;
int A[100][100];
int c[100],f[100],d[100];
int t=1;

int main(){
  int i,j,l;
  int u,v,k;
  int B[100][100];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(l=0;l<k;l++){
      scanf("%d",&B[i][l]);
    }
    for(j=0;j<n;j++){
      A[i][j]=0;
      for(l=0;l<k;l++){
	if(B[i][l]==j+1){
	  A[i][j]=1;
	}
      }
    }
  }
  DFS();
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
void DFS(void){
  int i;
  for(i=0;i<n;i++){
    c[i]=0;
  }
  for(i=0;i<n;i++){
    if(c[i]==0){
      visit(i);
    }
  }
}
void visit(int i){
  int j;
  c[i]=1;
  d[i]=t;
  t++;
  for(j=0;j<n;j++){
    if(A[i][j]==0) continue;
    if(c[j]==0){
      visit(j);
    }
  }
  c[i]=2;
  f[i]=t;
  t++;
}

