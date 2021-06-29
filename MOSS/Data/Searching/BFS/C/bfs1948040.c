#include<stdio.h>
void visit(int);
int d(void);
void e(int);
 
int map[101][101];
int Q[101],n,head=0,tail=0,color[101],G[101];
int main()
{
  int i,j,v,vv,m,u,k;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    color[i]=0;
    for(j=0;j<n;j++){
      map[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&m);
    for(j=0;j<m;j++){
      scanf("%d",&vv);
      map[v-1][vv-1]=1;
    }
  }
 
  for(j=0;j<n;j++){
    if(map[0][j]==1){
      color[j]=0;
    }
  }
  color[0]=1;
  G[0]=0;
  e(0);
  while(head!=tail){
    u=d();
    for(k=0;k<n;k++){
      if(map[u][k]==1 && color[k]==0){
	color[k]=1;
	G[k]=G[u]+1;
	e(k);
      }
      color[u]=2;
    }
  }
   
 
   
  for(i=0;i<n;i++){
    if(color[i]==2){
      printf("%d %d\n",i+1,G[i]);
    }
    else printf("%d -1\n",i+1);
  }
  return 0;
}
 
int d()
{
  int x;
  x=Q[head];
  if(head+1==100){
    head=0;
  }
  else head=head+1;
  return x;
}
 
void e(int x)
{
  Q[tail]=x;
  if(tail+1==100){
    tail=0;
  }
  else tail=tail+1;
}