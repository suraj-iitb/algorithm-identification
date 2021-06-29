#include <stdio.h>

int SelectionSort(int A[], int n)
{
  int i,j,t,mini;
  int count=0;
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if (A[j]<A[mini]){
        mini=j;
      }
    }
    if (mini!=i){
      t=A[i];
      A[i]=A[mini];
      A[mini]=t;
      count++;
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

  int count=SelectionSort(data,n);

  for(i=0;i<n-1;i++){
    printf("%d ",data[i]);
  }
  printf("%d\n%d\n",data[n-1],count);
  return 0;
}
