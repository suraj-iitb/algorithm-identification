
#include<stdio.h>

#define N 200

#define WHITE 0 
#define GRAY 5
#define BLACK -5



int array[N][N];
int d[N];
int f[N];
int color[N];
int time_count=0;
int number;


void depthsearch(int u){

  int i;
  
  color[u]=GRAY;
  d[u]=++time_count;

  for(i=0;i<number;i++){
   
    if(color[i]==WHITE && array[u][i]==1){depthsearch(i);}

  }

  color[u]=BLACK;
  f[u]=++time_count;

}







void depth( ){
 
  int i;
  
  //白の初期化
  for(i=0;i<number;i++){
    color[i]=WHITE;
   
  }


  for(i=0;i<number;i++){
    if(color[i]==WHITE){depthsearch(i);}

  }

  
  for(i=0;i<number;i++){
   
    printf("%d %d %d\n",i+1,d[i],f[i]);


  }
  


}


int main(){

  
  
  scanf("%d",&number);


  int me;
  int count;


  int i,j;
  int u;


for(i=0;i<number;i++){
    for(j=0;j<number;j++){
      array[i][j]=0;
    }
  }





 for(i=0;i<number;i++){
   scanf("%d",&me);
   scanf("%d",&count);
   
   for(j=1;j<count+1;j++){
     scanf("%d",&u);
     
     
     array[me-1][u-1]=1;
    
     
     
   }
 }



 
 
 depth();
 
  return 0;}

