#include <stdio.h>
int A[2000000],C[10001],B[2000000];
int main(){
  int i,n;
  scanf("%d",&n);
 
  for(i=0;i<n;i++) scanf("%d",&A[i]);


  for(i = 0;i<10001;i++)
    C[i] = 0;

  for(i=0;i<n;i++)
    C[A[i]]++;

  for (i = 1;i<10001;i++)
    C[i] = C[i] + C[i-1];

  for (i=n-1;i>=0;i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
	  }
  for(i=0;i<n-1;i++)
    printf("%d ",B[i]);
 printf("%d\n",B[n-1]);
return 0;
}
