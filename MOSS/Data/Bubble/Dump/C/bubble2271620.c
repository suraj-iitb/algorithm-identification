#include <stdio.h>

int main () {

  int i,j,n,c,len,array[100];

  scanf("%d",&len);

  for(i=0 ; i<len ; i++)
    scanf("%d",&array[i]);

  for(i=0 ; i<len ; i++){
    for(j=len-1 ; j>i ; j--){
      if(array[j] < array[j-1]){
        n = array[j-1];
        array[j-1] = array[j];
        array[j] = n;
        c++;
      }
    }
  }

  for(i=0 ; i<len ; i++){
    if(i==len-1)
      printf("%d",array[i]);
    else
      printf("%d ",array[i]);
  }
  printf("\n%d\n",c);
  
return 0;
}
