#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *, int);

int n;

int main(){
  int *A;
  int c;
  int i;
  
  scanf("%d",&n);
  if(n<1 || 100<n)exit(1);

  A=(int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || 100<A[i])exit(2);
  }

  c=bubbleSort(A,n);

  for(i=0; i<n; i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");

  printf("%d\n",c);
  
  return 0;
}

int bubbleSort(int *A, int n){
  int c=0;
  int i;
  int flag=1,a;

  while(flag){
    flag=0;
    for(i=n-1; 1<=i; i--){
      if(A[i]<A[i-1]){
	a=A[i];
	A[i]=A[i-1];
	A[i-1]=a;

	flag=1;
	c++;
      }
    }
    
  }
  
  return c;
}

