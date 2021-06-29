#include<stdio.h>
#define N 100
int main(void){
  int A[N],i,j,n;
  int t,count=0;
  int min;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j] < A[min]) min = j;
    }
    if(A[i]!=A[min]) count++;
    t = A[i];
    A[i] = A[min];
    A[min] = t;
  }

  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
}
