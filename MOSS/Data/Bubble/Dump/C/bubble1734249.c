#include <stdio.h>
#define X 100
int main(){
  int flag = 1;
  int i=0;
  int j,n,sum=0,temp;
  int A[X];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  while(flag){
    flag = 0;
    for(j=n-1; j>=1; j--){
      if(A[j]<A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag =1;
	sum++;
      }
      i++;    
    }
  }

  for(i=0; i<n; i++){
    printf("%d",A[i]);
    if(i!=n-1){
      printf(" ");
    }
  }

  printf("\n");

  printf("%d\n",sum);
  
  return 0;
}
