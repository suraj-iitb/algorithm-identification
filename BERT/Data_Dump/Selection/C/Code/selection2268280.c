#include<stdio.h>

#define N 100

int main(){
  int A[N];
  int b, a, j, i, min,count=0;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<a;i++){
    min = i;
    for(j=i;j<a;j++){
      if(A[j]<A[min]){
        min = j;
      }
    }
    if(A[i] != A[min]){
      count +=1;
    }
    b = A[i];
    A[i] = A[min];
    A[min] = b;
  }
  for(i=0;i<a-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[a-1]);
  printf("%d\n",count);
  
  return 0;
}
