#include<stdio.h>
#define N 100
void bubbleSort(int *,int);

int time=0;

int main(){
  int flag;
  int A[N];
  int i,j,length;

  scanf("%d",&length);
  for(i=0;i<length;i++)
    scanf("%d",&A[i]);

  bubbleSort(A,length);
  
    for(i=0;i<length-1;i++)
      printf("%d ",A[i]);
    printf("%d\n",A[i]);
    printf("%d\n",time);

    return 0;
}

void bubbleSort(int *A,int n){
  int flag=1;
  int j,i;
  int swap;
  while(flag){
    flag = 0;
  for(j=n-1;j>=1;j--){
    if(A[j]<A[j-1]){
      swap = A[j];
      A[j] = A[j-1];
      A[j-1] = swap;
      flag = 1;
      time++;
      
    }
  }
}
}
       

