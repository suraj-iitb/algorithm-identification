#include <stdio.h>
#define X 100

int main(){

  int i,j,n,sum=0,mini,temp,flag;
  int A[X];

  scanf("%d",&n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }


  for(i=0; i<=n-1; i++){
    mini = i;
    for(j=i; j<=n-1; j++){
      if(A[j]<A[mini]){
	mini = j;
	flag = 1;
      }
    }
    temp = A[i];
    A[i] = A[mini];
    A[mini] = temp;
    if(flag==1){
      sum++;
      flag=0;
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
