#include <stdio.h>

int bubbleSort();

int main() {
  int num;
  int i,j,count;
  int A[100];

    scanf("%d",&num);
    for(i = 0; i<num; i++)
      scanf("%d",&A[i]);
    
    count = bubbleSort(A, num);

    for(i = 0; i<num; i++){
      printf("%d",A[i]);
      if(i != num -1) printf(" ");
    }
    printf("\n%d\n",count);

    return 0;
    
}

int bubbleSort(int A[],int num){
  
  int flag = 1;
  int  i = 0;
  int j;
  int count = 0;
  int temp;
  
    while (flag){
      flag = 0;
      for (j =num-1; j >= i+1; j--){
	
	if (A[j] < A[j-1]){
	     
	  temp = A[j];
	  A[j] = A[j-1];
	  A[j-1] = temp;
	
	  flag = 1;
	  count++;

	}
      }
	  i++;
      
    }
    return count;
}
