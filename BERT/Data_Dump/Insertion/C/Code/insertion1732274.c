#include <stdio.h>

#define N 1000

int main()
{
  int i,j,num,A[N],key;

  scanf("%d",&num);
  for(i=1; i<=num; i++){
    scanf("%d",&A[i]);
  }


  for(i=1; i <= num; i++){
    key = A[i];
    j = i-1;

    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
      A[j+1] = key;
    }

    for(j=1; j<num; j++){
      printf("%d ",A[j]);
    }
    printf("%d\n",A[num]); 

  }

  return 0;

}
