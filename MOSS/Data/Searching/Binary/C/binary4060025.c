#include<stdio.h>

int main(){

  int N1,N2,i,j,key,count=0,left,mid,right;

  scanf("%d", &N1);
  int A[N1];
  for(i=0;i<N1;i++)scanf("%d",&A[i]);
  scanf("%d", &N2);
  int B[N2];
  for(i=0;i<N2;i++)scanf("%d",&B[i]);

  for(i = 0 ; i< N2 ; i++){
    j = 0;
    key = B[i];
    left = 0;
    right = N1;
    while(left < right){
      mid = (left + right) / 2;
      if (A[mid] == key){
	count++;
	break;
      }
      else if(key < A[mid])right = mid;
      else left = mid + 1;
      j++;
    }
  }

  printf("%d\n",count);

  return 0;
}




