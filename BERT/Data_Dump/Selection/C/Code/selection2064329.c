#include<stdio.h>

int main() {
  int A[100];
  int n, i, j, temp, min=1000, cout=0, k;

  scanf("%d\n",&n);
  
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);

  for (i=0; i<n; i++) {
    for (j=i+1; j<n; j++) {
      if (min>A[j]) {
        min=A[j];
        k=j;
      }
    }
    if (min<A[i]) {
        temp=A[i];
        A[i]=min;
        A[k]=temp;
        cout++;
    }
    min=1000;
  }
  for (i=0; i<n-1; i++)
    printf("%d ",A[i]);
  printf("%d",A[n-1]);
 
  printf("\n");
  printf("%d\n",cout);
  return 0;

}
