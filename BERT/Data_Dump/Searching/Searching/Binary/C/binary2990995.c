#include<stdio.h>
#include<stdlib.h>
int n1,count=0;

int binarySearch(int *A,int key);
int main(){
  int n2;
  int *A,*B;
  int i,j;
   
  scanf("%d",&n1);


   A  = (int *)malloc(n1 * sizeof(int));
   
  for(i=0;i<n1;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&n2);

  B  = (int *)malloc(n2 * sizeof(int));
   
    
    for(i=0; i<n2; i++){
      scanf("%d",&B[i]);
    }

    
    for(i=0;i<n2;i++){
      binarySearch(A,B[i]);
    }	 
	   
    printf("%d\n",count);

    return 0;
}


binarySearch(int *A,int key){
 int left = 0;
 int right;
 int mid;
  right = n1;
  
  while(left<right){
    mid = (left + right)/2;
    if(key == A[mid]){
      count++;
      return mid;
    }
    if(key >A[mid]){
      left = mid + 1;
    }
    else if(key < A[mid]){
      right = mid;
    }
  }
    return NULL;
  }
    

