#include<stdio.h>
#define NC 0
#define C -1
#define N 1000
#define W 0
#define G 1
#define B 2
int HAKO[N][N];
int color[N];
int Stack[N];
int d[N];
int f[N];
int h[N];
int num=0;
int time=0;
int n;

void push(int u){
  Stack[num]=u;
  num++;
  }
void pop(void){
  Stack[num]=-1;
  num--;
}
int next(int u){
  int i;
  for(i=1;i<=n;i++){
    if(HAKO[u][i]==C && color[i]==W) return i; 
      }
  return NC;
  }

void visit(int r){
  int u,v;
  push(r);
  color[r]=G;
  d[r]=++time;
    while(num!=0){
    u=Stack[num-1];
    v=next(u);
    // printf
    if(v!=NC){
      if(color[v]==W){
	push(v);
	color[v]=G;
	d[v]=++time;
      }
    }
    else{
      pop();
      color[u]=B;
      f[u]=++time;
      }
    

    }
  //  printf("%d",num);

}


void dfs(int u){
  int i;
  for(i=1;i<=u;i++) {
    if(color[i]==W) visit(i);
  }
};
int main(){
  int i,j,u,k,v;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=0;j<n;j++){
      HAKO[i][j]=NC;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);
    h[i]=0;
    color[i]=W;
    for(j=0;j<k;j++){
      if(k==0) break;
      scanf("%d",&v);
      HAKO[u][v]=C;
    }
  }
 
  dfs(n);
    for(i=1;i<=n;i++){
      printf("%d %d %d\n",i,d[i],f[i]);}  
  return 0;
}

