#include<stdio.h>
#include<stdlib.h>
void swap(int *,int *);

int main(void){
  int A[100];
  int i,j,N,x,min;
  int a,b;
  
  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  x = 0;
  for(i=0; i<N; i++){
    min = i;
    for(j=i; j<N; j++){
      if(A[j] < A[min]){
	min = j;
      }
    }
    a = A[i];
    b = A[min];
    if(b < a){
      x++;
    }
    swap(&a,&b);
    A[i] = a;
    A[min] = b;
  }
  for(i=0; i<N; i++){
    if(i != 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",x);
  return 0;
}

void swap(int *x,int *y){
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
