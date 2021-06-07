#include<stdio.h>

int binarySearch(int,int);
int A[100000];

int main(){

  int B[50000],N,M,i,count=0;

  scanf("%d",&N);
  
  for(i=0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }  

  scanf("%d",&M);
  
  for(i=0 ; i<M ; i++){
    scanf("%d",&B[i]);
  }  

  for(i=0 ; i<M ; i++){    

    if( binarySearch(N,B[i]) == 1)count++;

  }
    printf("%d\n",count);
    return 0;
  }

int binarySearch(int right,int key){

  int left=0,mid;

  while (left < right){
    mid = (left + right)/2;
      if(A[mid] == key){
        mid = 1;
	return mid;
      }else if(key < A[mid]){
	right = mid;
      }else{
	 left = mid + 1;
      }
  }
  mid=0;
  return mid;
}
	   

