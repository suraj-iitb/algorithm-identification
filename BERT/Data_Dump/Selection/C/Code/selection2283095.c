#include<stdio.h>
#define Max 100

int main(){
  int A[Max];
  int i,j,n,x;
  int temp,min,time=0;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++) scanf("%d",&A[i]);

  for(i=0 ; i<n ; i++){
    min = A[i];
    for(j=i ; j<n ; j++){
      if(A[j] < min){
        min = A[j];
        x = j;
      }
    }
    if(A[i] != min){
    temp = A[i];
    A[i] = min;
    A[x] = temp;
    time++;
    }
  }

  for(i=0 ; i<n-1 ; i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);
  printf("%d\n",time);

  return 0;
}
