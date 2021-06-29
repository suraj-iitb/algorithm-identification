#include <stdio.h>
int main()
{
  int i,j,c,n,v,A[1000];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(c=0;c<n;c++){
      printf("%d",A[c]);
      if(c<n-1)printf(" ");
    }
    printf("\n");
  }
  return 0;
}

