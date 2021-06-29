#include <stdio.h>
#define SIZE 100

int main(){

  int i,j,k;
  int n,array[SIZE],temp;

  //input
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }

  i=0;

  //sort
  for(i=1;i<n;i++){
    j=i;
    
    for(k=0;k<n;k++){
      if(k!=0) printf(" ");
      printf("%d",array[k]);
    }
    printf("\n");

    while((j > 0) && (array[j-1]>array[j])){
      temp = array[j-1];
      array[j-1] = array[j];
      array[j] = temp;

      j--;
    }
  }
  
  for(k=0;k<n;k++){
    if(k!=0) printf(" ");
    printf("%d",array[k]);
  }
  printf("\n");
  
  return 0;
}
