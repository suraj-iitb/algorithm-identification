#include<stdio.h>
#define MAX 100
#define L 1000
#define INF (1<<21)

int n,N[MAX][MAX],a[MAX];
void bfs(int);
int dequeue();
void enqueue(int);
int g = 0,t = 0,q[L];

int main(){
  int k,j,i,x,y,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      N[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&x,&k);
    x--;
    for(j=0;j<k;j++){
      scanf("%d",&y);
      y--;
      N[x][y]=1;
    }
  }
  bfs(0);
  return 0;
}
void enqueue(int z){
  q[t]=z;t=(t+1)%L;
}

int dequeue(){
  int c;
  c=q[g];
  g=(g+1)%L;
  return c;
}


void bfs(int d){
  enqueue(d);
  int i,v,u;
 for(i=0;i<n;i++){
   a[i]=INF;
 }
 a[d]=0;
   while(g != t){
     u=q[g];
     dequeue();
     for(v=0;v<n;v++){
       if(N[u][v] == 0){
         continue;
       }
       if(a[v] != INF){
         continue;
       }
       a[v] = a[u] + 1;
       enqueue(v);
     }
   }
   for(i=0;i<n;i++){
     printf("%d %d\n",i+1,(a[i] == INF ? (-1):a[i]));
   }
}


