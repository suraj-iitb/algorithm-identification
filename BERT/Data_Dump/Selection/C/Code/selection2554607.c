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

void swap(int *A,int i,int j)
{
  int x;
  x=A[i];
  A[i]=A[j];
  A[j]=x;
}

int selection_sort(int *A,int n)
{
  int i,j,minj,s;
  s=0;
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]) minj=j;
    }
    swap(A,i,minj);
    if(i!=minj) s++;
  }
  return s;
}

int *int_read()
{
  int i,n;
  int *A;
  scanf("%d",&n);
  printf("%d\n",n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  return A;
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
  swap=selection_sort(A,n);
  int_display(A,n);
  printf("%d\n",swap);
  return 0;
}
