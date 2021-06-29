#include <stdio.h>
 
int main()
{
 int A[1000], v;
 int i, j, n;
 scanf("%d", &n);
 for(i=0; i<n; i++) scanf("%d", A+i);
 for(i=0; i<n; i++){
  v = A[i];
  j=i-1;
  while(j>=0 && v<A[j]){
   A[j+1] = A[j];
   j--;
  }
  A[j+1] = v;
  printf("%d", A[0]);
  for(j=1; j<n; j++){
   printf(" %d", A[j]);
  }
  puts("");
 }
 return(0);
}
