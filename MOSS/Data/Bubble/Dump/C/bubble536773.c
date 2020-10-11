#include <stdio.h>


int BubbleSort(int A[], int n)
{
  int i,j,t;
  int count=0;
  for(i=0;i<n;i++){
    for(j=n-1;i<j;j--){
      if (A[j]<A[j-1]){
        t=A[j];
        A[j]=A[j-1];
        A[j-1]=t;
        count++;
      }
    }
  }
  return count;
}

int main()
{
  int n,i;
  int data[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }

  int count=BubbleSort(data,n);

  for(i=0;i<n-1;i++){
    printf("%d ",data[i]);
  }
  printf("%d\n%d\n",data[n-1],count);
  return 0;
}
