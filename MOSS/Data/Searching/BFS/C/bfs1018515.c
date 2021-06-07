#include<stdio.h>
int color[105],k[105],d[105],G[105][105],Qu[100];
int u,v,j=0,count=1,n;
void Enqueue(int s){
  int i=0;
  while(i<k[s]){ 
    Qu[count]=G[s][i];
    ++i;
    ++count;
  }
}
int Dequeue(){
  int head,i;
  head=Qu[0];
  for(i=0;i<count;i++)
    Qu[i]=Qu[i+1];
  --count;
  return head;
}
void BFS(int s){
  int i;
  Qu[0]=s;
  for(i=1;i<=n;i++){
    color[i]=0;
    d[i]=-1;
  }
  color[s]=2;
  d[s]=0;
  Qu[0]=s;
  Enqueue(s);
  while(Qu[0]!=NULL){
    u=Dequeue();
    for(i=0;i<k[u];i++)
      if(color[G[u][i]]==0){
	color[G[u][i]]=2;
	d[G[u][i]]=d[u]+1;
	Enqueue(G[u][i]);
      }
    color[u]=1;
  }
}
int main(void){
  int i,j,k1;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k1);
    k[u]=k1;
    for(j=0;j<k[u];j++){
      scanf("%d",&v);
      G[u][j]=v;
    }  
  } 
  BFS(1);
  for(i=1;i<=n;i++)
    printf("%d %d\n",i,d[i]);
  return 0;
}
