#include <stdio.h>
#define M 100

void bubbleSort(int[],int);
int count = 0;

int main (){
    int n,i;
    int A[M+1];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    bubbleSort(A,n);
    printf("%d\n",count);

    return 0;

}

void bubbleSort(int A[],int N){
  int j,i,temp;

  for (i = 0 ;i<N-1;i++){
    for (j= N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	count++;
      }
    }
  }
  for (i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
   printf("%d\n",A[i]);
    
}

