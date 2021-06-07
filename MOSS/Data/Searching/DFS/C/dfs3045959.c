#include<stdio.h>

#define N 110
#define Initial 0
#define Medium 1
#define End 2

void Root(int,int);

int Graph[N][N];
int Ver[N];
int Disc[N];
int Fin[N];
int count;

int main(){
  int loop;
  int i,j;
  int vertex,adjacent,adnum;

  scanf("%d",&loop);
  for(i=1;i<loop+1;i++){
    scanf("%d %d",&vertex,&adjacent);

    for(j=1;j<adjacent+1;j++){

      scanf("%d",&adnum);

      if(adnum!=0){
	Graph[vertex][adnum]=1;
      }

      else{
	Graph[vertex][adnum]=0;
      }
    }
    
  }
  
  for(i=1;i<loop+1;i++){
    Ver[i]=Initial;
  }

  count=0;

  for(i=1;i<loop+1;i++){
    
    if(Ver[i]==Initial){
      Root(i,loop+1);
    }
  }

  for(i=1;i<loop+1;i++){
    printf("%d %d %d\n",i,Disc[i],Fin[i]);
  }

  return 0;
}

void Root(int num,int plusloop){
  int i;
  
  Ver[num]=Medium;

  count++;

  Disc[num]=count;

  for(i=1;i<plusloop;i++){

    if(Graph[num][i]==Initial){
      continue;
    }
    
    if(Ver[i]==Initial){
      Root(i,plusloop);
    }
  }

  Ver[num]=End;

  count++;
  
  Fin[num]=count;
}

