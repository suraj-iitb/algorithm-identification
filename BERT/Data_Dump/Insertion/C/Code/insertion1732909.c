#include <stdio.h>
#define N 100

int main(){
  int A[N];
  int a,v,i,j,k;

  scanf("%d",&a);
  for(i=0;i<a;i++) scanf("%d",&A[i]);
  for(i =0;i<a;i++){
    k=i;
    v = A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0;k<a;k++){
      printf("%d",A[k]);
      if(k==a-1){
	printf("\n");
	break;
      }  
      printf(" ");
    }
  }
  
  return 0;
}
