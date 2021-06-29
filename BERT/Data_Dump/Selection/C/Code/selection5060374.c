#include<stdio.h>
#include<stdlib.h>

int main(){
  int array[100];
  int length, i, j, minj, key=0, count=0;

  scanf("%d",&length);
  if(length<1 || length>100) exit(1);

  for(i=0; i <= length-1;i++){
    scanf("%d",&array[i]);
    if(array[i]<0 || array[i]>100) exit(1);
  }

  for(i=0; i<=length-1;i++){
    minj = i;
    for(j=i; j<=length-1; j++){
      if(array[j]<array[minj]) minj = j;
    }
    if(i != minj) count++;
    key = array[i];
    array[i] = array[minj];
    array[minj] = key;
  }

  for(i=0; i<=length-1; i++){
    printf("%d",array[i]);
    if(i != length-1) printf(" ");
  }

  printf("\n%d\n",count);

  

  return 0;
}

