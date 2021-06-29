#include<stdio.h>
#define LONG 100
#define N 100000000
int  A[LONG];
int B[LONG][LONG];
int atama,ketu;
int d[LONG];
int total;
void enqueue(int x){
  A[ketu] = x;
  ketu = (ketu+1) % LONG;
}
int dequeue(){
  int  x = A[atama];
  atama = (atama+1)%LONG;
  return x;
}
int enpty(){
  if(ketu == atama)return 1;
  else return 0;
}
void ooh(int s){
  int i,u,v;
   enqueue(s);
  for(i=0;i<total;i++){
    d[i] = N;
  }
  d[s] = 0;
  while(!enpty()){
    u = dequeue();
    for(v=0;v<total;v++){
      if(B[u][v] == 0)continue;
      if(d[v] != N)continue;
      d[v] = d[u] + 1;
      enqueue(v);
    }
  }
  for(i=0;i<total;i++){
    printf("%d %d\n",i+1,((d[i] == N)? -1 : d[i]));
  }
}
int main(){
  int k,u,v,i,j;
   scanf("%d",&total);
  for(i=0;i<total;i++){
    for(j=0;j<total;j++){
      B[i][j] = 0;
    }
  }
  for(i=0;i<total;i++){
    scanf("%d%d",&u,&k);
    u--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      B[u][v] = 1;
    }
  }
  ooh(0);
  return 0;
}
