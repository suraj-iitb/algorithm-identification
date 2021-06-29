#include <stdio.h>
#define MAX 100
int main()
{
  int i,j,k=0,a,l,mini;
  int A[MAX];

  scanf("%d",&l);
  for(i=0;i<l;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<l;i++){
    mini=i;
    for(j=i;j<l;j++){
      if(A[j]<A[mini]){
        mini=j;
      }
    }
    if(i!=mini){
      k++;
    }
    a=A[mini];
    A[mini]=A[i];
    A[i]=a;
    printf("%d",A[i]);
    if(i!=l-1){
      printf(" ");
    }
  }
  printf("\n%d\n",k);
  return 0;
}
