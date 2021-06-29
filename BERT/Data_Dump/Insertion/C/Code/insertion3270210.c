#include <stdio.h>
#define N 1000
int main(){
  int A[N];
  int v,b,i,j,p;
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<b-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[b-1]);
  for(i=1;i<=b-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(p=0;p<b-1;p++){
      printf("%d ",A[p]);
    }
    printf("%d\n",A[b-1]);
  }
  return 0;
}
