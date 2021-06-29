#include<stdio.h>
#define xiro 0
#define GRAY 1
#define kuro 2

int sonnnkakotoaru[101];
int A[101][101];
int d[101];
int f[101];
int anoaieibneoijaildjglaisjenbliesj,n;
void dfs(void);
void visit(int);

























































































































































































































































































































int main()
{
  int i,j,k,id,kn;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&kn);
    for(j=0;j<kn;j++){
      scanf("%d",&k);
      A[id][k]=1;
    }
  }
  dfs();
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}








































































































//nnnnnnnnnnnnnnnnnnnnnnnoiawjfoweijodvnaiejvnoirfgnavrdfngaovirjdnofianoidrjfnab
//aeeaeage
//egegasegggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg











void dfs (void){
  int i,j;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(A[i][j]==1){
	if(sonnnkakotoaru[i]==xiro){
	  visit(i);
	}
      }
    }
  }
}
void visit(int u){
  int i;
  sonnnkakotoaru[u]=GRAY;
  d[u]=++anoaieibneoijaildjglaisjenbliesj;
  for(i=1;i<=n;i++){
    if(A[u][i]==1){
      if(sonnnkakotoaru[i]==xiro){
	visit(i);
      }
    }
  }
  sonnnkakotoaru[u]=kuro;
  f[u]=++anoaieibneoijaildjglaisjenbliesj;
}
      
    
  
  
 


