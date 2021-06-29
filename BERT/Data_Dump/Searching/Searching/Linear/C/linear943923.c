#include <stdio.h>
#define MAX 10000
int main(){
  int a,b,A[MAX],B[MAX],count=0,i,j;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&B[i]);
  }
  
  for(i=0;i<b;i++){
    for(j=0;j<a;j++){
      if(A[j]==B[i]){count++;break;}
    }
  }
  printf("%d\n",count);
  return 0;
}
