#include<stdio.h>
#define N 100

int main(){
  int n,i,j,temp;
  int array[N];
  int flag = 0;

  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    scanf("%d",&array[i]);
  }

  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(array[j] < array[j-1]){
	temp = array[j-1];
	array[j-1] = array[j];
	array[j] = temp;
	flag++;
      }
    }
  }

  for(i=0; i<n; i++){
    printf("%d",array[i]);
    if(i < n-1){
      printf(" "); 
    }
  }
  printf("\n");
  printf("%d\n",flag);
  
  

  return 0;
}


