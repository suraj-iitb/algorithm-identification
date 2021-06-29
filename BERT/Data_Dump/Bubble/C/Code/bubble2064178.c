#include<stdio.h>

int main() {
  int A[100];
  int n, i, j, temp, flag=1, cout=0;

  scanf("%d\n",&n);
  
  for(i=0; i<n; i++)
    scanf("%d",&A[i]);

  while (flag) {
    flag=0;
    for (j=n-1; j>0; j--) {
      if (A[j]<A[j-1]) {
        temp=A[j];
        A[j]=A[j-1];
        A[j-1]=temp;
        flag=1;
        cout++;
      }
    }
  }
  for (i=0; i<n-1; i++)
    printf("%d ",A[i]);
  printf("%d",A[n-1]);
 
  printf("\n");
  printf("%d\n",cout);
  return 0;

}
