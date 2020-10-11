#include<stdio.h>

void bubbleSort(int *A, int N);

int main(void){
  int a[100],n;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  bubbleSort(a,n);

  return 0;
}

void bubbleSort(int *A, int N){

  int tmp;
  int i,j;
  int flag=1,cnt=0;

  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	cnt++;
      }
    }
  }

  for(i=0;i<N-1;i++)
    printf("%d ",A[i]);

  printf("%d\n",A[N-1]);
  printf("%d\n",cnt);
}

