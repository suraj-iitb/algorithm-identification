#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){

  int N,i,v,j,b,minj;
  int a[100]={};
  int temp;
  int time=0;

  scanf("%d",&N);

    for(i=0;i<N;i++){
   scanf("%d",&a[i]);
  } 


  for(i=0; i<N-1;++i){
    minj = i;

    for(j=i;j<N;++j){
      if(a[j]<a[minj]){
	minj=j;

      }
    }
      if(a[minj] != a[i]){
       temp=a[i];
      a[i]=a[minj];
      a[minj]=temp;
        time++;
      }

      }
      
      
     
 
    for(b=0;b<N;b++){

    printf("%d",a[b]);

    if(b!=N-1)
      printf(" ");

    }
    	printf("\n");
	printf("%d\n",time);
    }


  
