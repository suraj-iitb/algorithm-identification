#include<stdio.h>
#define N 100
int main()
{
  int i,j,l,v,z,A[N];
  
  scanf("%d",&l);
  
  for(i = 1;i <= l;i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 1;i <= l;i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(z = 1;z < l;z++){
      printf("%d ",A[z]);
    }
    printf("%d",A[z]);
    printf("\n");
  }
  return 0;
}
