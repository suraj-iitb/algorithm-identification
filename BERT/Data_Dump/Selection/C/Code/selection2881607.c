#include<stdio.h>
#define MAX 101

int count = 0;

void selection_sort(int n,int *A){
  int i,j,tmp,index;
  for(i=0;i<n-1;i++){
    index = i;
    for(j=i+1;j<n;j++)
      if(A[j]<A[index])
        index = j;
    tmp = A[i];
    A[i] = A[index];
    A[index] = tmp;
    if(index!=i)count++;
  }
}

int main(){
  int n,i;
  int a[MAX];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  selection_sort(n,a);
  for(i=0;i<n-1;i++)
    printf("%d ",a[i]);
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}

