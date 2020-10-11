#include<stdio.h>
int selectionsort(int A[100],int n);
int A[100],out=0;
int main()
{
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  selectionsort(A,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",out);
  return 0;
}

int selectionsort(int A[],int n)
{
  int temp,i,j,mini;
  for(i=0;i<n-1;i++){
    mini = i;

    for(j=i+1;j<n;j++){
      if(A[j]<A[mini]) mini = j;
    }

      if(A[i]>A[mini]){
	temp = A[i];
	A[i] = A[mini];
	A[mini] = temp;
	out++;
      }
  }
}
