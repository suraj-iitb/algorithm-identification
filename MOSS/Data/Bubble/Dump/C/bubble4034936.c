#include<stdio.h>

#define N 100

int bubbleSort(int*,int);

int main(){
  int i,j,A[N],count;
  
  scanf("%d",&i);

  for(j=0;j<i;j++){
    scanf("%d",&A[j]);
  }

  count=bubbleSort(A,i);

  printf("%d",A[0]);
  for(j=1;j<i;j++){
    printf(" %d",A[j]);
  }
  

  printf("\n%d\n",count);

  return 0;
}

int bubbleSort(int *A,int n){
  int i,j,temp,count=0;

  for(i=0;i<n;i++){
    for(j=n-1;j>0;j--){
      if(*(A+j)<*(A+j-1)){
	temp=*(A+j);
	*(A+j)=*(A+j-1);
	*(A+j-1)=temp;
	count++;
      }
    }
  }
  
 
  return count;
}
	
    

