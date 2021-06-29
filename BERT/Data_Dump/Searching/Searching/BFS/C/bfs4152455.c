#include<stdio.h>
#define  MAX 100
typedef struct{//all number is 0
  int color;//0 white /1 gray /2 black
  int distance;
}Graf;

Graf A[MAX];//本体
int G[MAX][MAX];//グラフ
int Q[MAX];//次に候補
int head,tail;

void enque(int x){
  Q[tail]=x;
  tail=(tail+1)%MAX;
}
int deque(void){
  int x=Q[head];
  head=(head+1)%MAX;
  return x;
}

void BFS(int u,int n){
  int i;
  int v;
  if(A[u].color!=0)return;
  A[u].color=1;
  enque(u);
  	
  while(head!=tail){ //not empty
   
    u=deque();
    
    for(v=0;v<n;v++){
      if(G[u][v]==1 && A[v].color==0){
	A[v].color=1;
	A[v].distance = A[u].distance+1;

	enque(v);
      }
    }
    A[u].color=2;
  }
}


int main(){
  int id;
  int n;
  int agree;
  int i,j;
  int hand;
 
  for(i=0;i<100;i++){ //all 0
    A[i].color=A[i].distance=0; // all 0
    
    for(j=0;j<100;j++){
      G[i][j]=0;
    }
  }

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&agree);
    
    for(j=0;j<agree;j++){
      scanf("%d",&hand);
      G[id-1][hand-1]=1;
    }
  }
    
    BFS(0,n);
    
  for(i=0;i<n;i++){//OUTPUT
    if(A[i].distance==0 && i!=0)printf("%d -1\n",i+1);
    else printf("%d %d\n",i+1,A[i].distance);
  }
  
  return 0;
}

