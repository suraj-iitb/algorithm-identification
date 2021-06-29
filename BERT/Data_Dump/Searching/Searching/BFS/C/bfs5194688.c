#include<stdio.h>
#define M 100
int a[M][M],n;
int head=0,tail=0;
int Q[M],d[M],c[M];
void enqueue(int x){
  Q[tail]=x;
  tail++;
}
int dequeue(void){
  int x;
  x=Q[head];
  head++;
  return x;
}
void b(int x){
  int i,y,z;
  enqueue(x);
  for(i=0;i<n;i++){
    d[i]=-1;
    c[i]=0;
  }
  c[x]=1;
  d[x]=0;
  while(head!=tail){
    y=dequeue();
    for(z=0;z<n;z++){
      if(a[y][z]!=0 && c[z]==0){
        c[z]=1;
        d[z]=d[y]+1;
        enqueue(z);
      }
    }
    c[y]=2;
  }
}

int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[u][v]=1;
    }
  }
  b(0);
  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}
