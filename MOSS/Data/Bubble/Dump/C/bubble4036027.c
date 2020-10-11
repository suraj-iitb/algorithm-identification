#include<stdio.h>
#define N 100

void bubbleSort(int A[],int n);
  
int main(){
  int buf,n,i,j=0,flag = 0;
  int A[N];
  
  scanf("%d",&n);
  
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<n;i++){
    for(j=n-1;j>=i;j--){
      if(A[j+1]<A[j]){
	buf = A[j+1];
	A[j+1] = A[j];
	A[j] = buf;
	flag++;
      }
    }
  }
  
  bubbleSort(A,n);
  printf("%d\n",flag);
  
  return 0;
}

void bubbleSort(int A[],int n){
  int i;
  
  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

