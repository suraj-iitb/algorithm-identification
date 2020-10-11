#include <stdio.h>

#define N 100

int main(){
  int i,j,k,n,temp,count=0,array[N];
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&array[i]);
  }
  
  for(i=0; i<n; i++){
    for(j=n-1; j>i; j--){
      if(array[j]<array[j-1]){
	temp = array[j];
	array[j] = array[j-1];
	array[j-1] = temp;
	count++;
      }
    }
  }  

  for(i=0; i<n; i++){
    if(i > 0) printf(" ");
    printf("%d",array[i]);
  }
  printf("\n%d\n",count);

  return 0;  
}
