#include <stdio.h>
#define MAX 100
int main()
{
  int i,j,k=0,a,l;
  int A[MAX];

  scanf("%d",&l);
  for(i=0;i<l;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<l;i++){
    for(j=l-1;j>i;j--){
      a=A[j-1];
      if(a>A[j]){
        A[j-1]=A[j];
	A[j]=a;
        k++;
      }
    }
    printf("%d",A[i]);
    if(i != l-1){
      printf(" ");
    }
  }
  printf("\n%d\n",k);

  return 0;
}
