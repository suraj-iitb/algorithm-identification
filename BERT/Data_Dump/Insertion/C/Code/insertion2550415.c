#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){

  int N,i,v,j,b;
  int a[100]={};

  scanf("%d",&N);

  for(i=0;i<N;i++){
   scanf("%d",&a[i]);
  } 

  for(i=0;i<N;i++){
    v=a[i];
    j=i-1;

    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }  
    for(b=0;b<N;b++){

    printf("%d",a[b]);

    if(b!=N-1)
      printf(" ");

    }
    	printf("\n");
    }


  }
  
