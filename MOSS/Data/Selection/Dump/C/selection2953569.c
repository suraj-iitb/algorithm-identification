#include<stdio.h>
#define MAX 100

main(){
  int n;
  int i,j;
  int min,t,c=0;
  int A[MAX];

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  for(i=0;i<n;i++){
    min=i;
    for(j=i+1;j<n;j++){
      if(A[j]<A[min])min=j;
    }
    t=A[i];
    A[i]=A[min];
    A[min]=t;
    if(min!=i)c++;
  }

  printf("%d",A[0]);
  for(i=1;i<n;i++){
    printf(" %d",A[i]);
  }
  printf("\n");
  printf("%d\n",c);


  return 0;
}
  

  

