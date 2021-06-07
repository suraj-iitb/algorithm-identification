#include<stdio.h>
#define MAX 101
void dfs (int);
void visit(int,int);
int ar[MAX][MAX],time=0,color[MAX],d[MAX][2];
int main(){
int n,i,j,m,l,k;
for(i=0;i<MAX;i++){
  for(j=0;j<MAX;j++){
    ar[i][j]=0;
  } 
 }



 scanf("%d",&n);

 for(i=1;i<=n;i++){
   scanf("%d",&m);
   scanf("%d",&l);
   for(j=1;j<=l;j++){	
     scanf("%d",&k);
     ar[i][k]=1;
   }
 }
 dfs(n);
 for(i=1;i<=n;i++){
   printf("%d %d %d\n",i,d[i][0],d[i][1]);
 }

 return 0;
}
void dfs(int u){
  int i;
  for(i=1;i<=u;i++){
    color[i]=0;
  }
  time=0;
  for(i=1;i<=u;i++){
    if(color[i]==0){
      visit(i,u);
    }
  }
}
void visit(int u,int p){
  int i;
  color[u]=1;//1はGRAY
  d[u][0]=++time;
  for(i=1;i<=p;i++){
    if(color[i]==0 && ar[u][i]==1){
      visit(i,p);
    }
  }
    color[u]=2;
    d[u][1]=++time;


}

