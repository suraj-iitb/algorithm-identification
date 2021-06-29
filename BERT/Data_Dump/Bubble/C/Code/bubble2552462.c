#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdlib.h>

void int_display(int *A,int n)
{
  int i;
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
}

int bubble_sort(int *A,int n)
{
  int i,j,Aj,swap;
  swap=0;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
        Aj=A[j];
        A[j]=A[j-1];
        A[j-1]=Aj;
        swap++;
      }
    }
  }
  return swap;
}

int main()
{
  int *A;
  int i,n,swap;
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  swap=bubble_sort(A,n);
  int_display(A,n);
  printf("%d\n",swap);
  return 0;
}
