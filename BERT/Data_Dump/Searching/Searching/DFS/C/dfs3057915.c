#include<stdio.h>
#include<stdlib.h>
#define WHITE 1
#define GRAY 2
#define BLACK 3
int t=0;
typedef struct{
  int id;
  int *child; //子供のIDを保存
  int count; //子供の数
  int color;
  int d;
  int f;
}Vertex;
int visit(Vertex *A,int u){
  int i;
  A[u].color=GRAY;
  A[u].d=++t;
  for(i=0;i<A[u].count;i++){
    if(A[A[u].child[i]].color==WHITE){
      visit(A,A[u].child[i]);
    }
  }
  A[u].color=BLACK;
  A[u].f=++t;
}
void dfs(Vertex *A,int n){
  int i;
  for(i=0;i<=n;i++){
    A[i].color=WHITE;//1
  }
  for(i=1;i<n;i++){
    if(A[i].color==WHITE){
      visit(A,A[i].id);
    }
  }
}
int main(){
  int n,i,j;
  int id,num,col,x;
  Vertex *A;
  
  scanf("%d",&n);//入力(ノードの数)
  A=(Vertex *)malloc(sizeof(Vertex)*(n+1));
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&num);//入力(ノードのIDと子供の数)
    A[id].id=id;//ノードのID
    A[id].count=num;//ノードの子供の数
    A[id].child=(int*)malloc(sizeof(int)*num);//子供の数だけ動的確保
    for(j=0;j<num;j++){//子供のIDを格納
      scanf("%d",&x);
      A[id].child[j]=x;
    }
  }
  dfs(A,n);
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,A[i].d,A[i].f);
  }
  return 0;
}

