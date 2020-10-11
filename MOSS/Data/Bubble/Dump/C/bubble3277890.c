#include<stdio.h>
#define N 100

void bubbleSort(int *,int);

int main(){
  int n,i;
  int A[N];
  
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,n);
  return 0;
}

void bubbleSort(int *A,int n){
  int i,j;
  int flag,swap,count = 0;
  flag = 1;
    i = 0;
    while(flag){
       flag = 0;
       for(j = n - 1; j >= i + 1; j--){
           if(A[j] < A[j - 1]){
	   swap = A[j];
	   A[j] = A[j - 1];
	   A[j - 1] = swap;
	   count++;
	   flag = 1;
       }
    }
    i++;
  }
    for(i = 0; i < n; i++){
      if(i == n - 1) printf("%d",A[i]);
      else printf("%d ",A[i]);
    }
    
  printf("\n%d\n",count);

}

