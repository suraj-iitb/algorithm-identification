#include<stdio.h>
#include<stdlib.h>

int selectionSort(int *, int);

int n;

int main(){
  int i;
  int *A;
  int c;

  scanf("%d",&n);
  if(n<1 || 100<n)exit(1);

  A=(int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || 100<A[i])exit(2);
  }

  c=selectionSort(A,n);

  for(i=0; i<n; i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");

  printf("%d\n",c);
  
  return 0;
}

int selectionSort(int *A, int n){
  int c=0;
  int i,j,min;
  int a;

  for(i=0; i<n; i++){
    min=i;
    for(j=i; j<n; j++){
      if(A[j]<A[min])min=j;
    }
    if(A[i]!=A[min]){
      a=A[i];
      A[i]=A[min];
      A[min]=a;
      c++;
    }
  }

  return c;
}

