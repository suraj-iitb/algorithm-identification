#include <stdio.h>

#define N 100

int main(void){

  int i,j,n,tmp,c=0;
  int arr[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(arr[j] < arr[j-1]){
	tmp = arr[j];
	arr[j] = arr[j-1];
	arr[j-1] = tmp;
	c++;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",arr[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n",c);
  
  return 0;
}

