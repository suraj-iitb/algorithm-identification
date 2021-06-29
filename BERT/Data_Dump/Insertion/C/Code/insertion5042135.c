#include <stdio.h>
#define N 100
int main(){
  int inte,i,j,k,key,array[N];
  scanf("%d",&inte);
  if(inte>100 || inte < 1) printf("please input 1<= N <= 100");
  for(i=0;i<inte;i++)
    scanf("%d",&array[i]);
  for(i=1;i<inte;i++){
    for(k=0;k<inte;k++){
      printf("%d",array[k]);
      if(k != inte-1) printf(" ");
    }
    printf("\n");
    key = array[i];
    j=i-1;
    while (j >= 0 && array[j] > key){
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = key;
  }
  for(k=0;k<inte;k++){
    printf("%d",array[k]);
    if(k != inte-1) printf(" ");
  }
  printf("\n");
  return 0;
}

