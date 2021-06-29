#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j,a;
  int n,*array;
  int key;

  scanf("%d",&n);

  array =(int *)malloc(n * sizeof(int));
  
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }

  for(i=1;i<=n;i++){

    
    for(a=0;a<n;a++){
      printf("%d",array[a]);
      if(a!=n-1) printf(" ");
    }
    printf("\n");

    
    key=array[i];
    j=i-1;
    while(j>=0 && array[j]>key){
      array[j+1]=array[j];
      j--;
    }
    array[j+1]=key;


  }
  
  return 0;
}

