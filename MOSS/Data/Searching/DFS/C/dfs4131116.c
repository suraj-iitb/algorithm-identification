#include<stdio.h>

typedef struct{//all number is 0
  int color;//0 white /1 gray /2 black
  int start;
  int finish;
}Graf;


Graf A[100];
int G[100][100];
int total_time=0;


void DFS(int u,int n){
  int i;

  if( A[u].color!=0)return;
  total_time++;
  A[u].color=1;

  A[u].start=total_time;
  
  for(i=0;i<n;i++){
    if(G[u][i]==1 && A[i].color==0){
      DFS(i,n);
    }
  }
  
  total_time++;
  
  A[u].color=2;
  A[u].finish=total_time;
 
}


int main(){
  
  int id;
  int n;
  int num;
  int i,j;
  int hand;
 
  for(i=0;i<100;i++){ //all 0
    A[i].color=A[i].start=A[i].finish=0; // all 0
    
    for(j=0;j<100;j++){
      G[i][j]=0;
    }
  }

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&num);
    
    for(j=0;j<num;j++){
      scanf("%d",&hand);
      G[id-1][hand-1]=1;
    }
  }
  
  for(i=0;i<n;i++){
    DFS(i,n);
  }
  
  for(i=0;i<n;i++){//OUTPUT
    printf("%d %d %d\n",i+1,A[i].start,A[i].finish);
  }
  
  return 0;
}


   

