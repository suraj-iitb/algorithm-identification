#include<stdio.h>
#define N 100
void swap(int *,int *);

int main(){
  int flag,i,j,n,count=0;
  int A[N];
  
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  
  flag = 1;
  i=0;
  
  while(flag){
    flag = 0;
    
    for (j=n-1;j>=i+1;j--){
      if( A[j] < A[j-1]){
	swap(&A[j], &A[j-1]);
	count++;
      flag = 1;
      }
    }
    i++;
    
  }
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

void swap(int *a,int *b){
  int temp;
  
  temp = *a;
  *a=*b;
  *b=temp;
}

