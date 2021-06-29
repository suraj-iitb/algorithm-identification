#include<stdio.h>
#include<stdlib.h>
int n,**array,**timerecord;
//array仕様
//二次元配列　各行のindex[0]は探索済かどうか、それ以外のindexはつながってるかどうかの判断
//timerecod[0]はstart time, timerecord[1]はfinish time
void record(int,int*);

int main(){
  int m,i,j,k,l,time=0;
  scanf("%d",&n);

  timerecord = malloc(sizeof(int*)*2);
  for(i=0;i<2;i++)timerecord[i]=malloc(sizeof(int)*(n+1));
 
  array = malloc(sizeof(int *)*(n+1));
  for(i=0;i<n+1;i++)array[i]=malloc(sizeof(int)*(n+1));
  for(i=0;i<n+1;i++)for(j=0;j<n+1;j++)array[i][j]=0;
  
  k=n;
  while(k--){
    scanf("%d %d",&i,&l);
    while(l--){
      scanf("%d",&m);
      array[i][m]=1;
    }
  }
  
  for(i=1;i<n+1;i++)if(array[i][0]==0)record(i,&time);

  for(i=1;i<n+1;i++)printf("%d %d %d\n",i,timerecord[0][i],timerecord[1][i]);

  for(i=0;i<n+1;i++)free(array[i]);
  free(array);
  for(i=0;i<2;i++)free(timerecord[i]);
  free(timerecord);
  return 0;
}

void record(int k,int *time){
  int i,j;
  array[k][0]=2;
  timerecord[0][k]=++(*time);
  for(i=1;i<n+1;i++){
    if(array[i][0]==0 && array[k][i] == 1){//判別条件　行先が探索済でない　かつ　つながってる場所
      
      for(j=0;j<n+1;j++)array[j][i]=2;
      record(i,time);
    }
  }
  
  timerecord[1][k]=++(*time);
}
  
  


    
  
      
  
  
  

