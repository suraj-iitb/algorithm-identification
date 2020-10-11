#include<stdio.h>

int main (){

  int num, nums, i, j, cnt = 0, mini;

  scanf("%d", &num);

  int A[num];

  for(i=0; i<num; i++)
    scanf("%d", &A[i]);

  for(i=0; i<num; i++){

    mini = i;

    for(j=i; j<num; j++){

      if(A[j] < A[mini])
	mini = j;

    }

    if(A[i]>A[mini]){
      nums = A[i];
      A[i] = A[mini];
      A[mini] = nums;
      cnt++;
    }

  }

  for(i=0; i<num; i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  printf("%d\n", cnt);

  
  return 0;
  
}
