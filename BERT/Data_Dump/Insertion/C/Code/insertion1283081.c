#include <stdio.h>

int main(void)
{
  int i,j,k,n,v;
  int A[1000];

  scanf ("%d",&n);
  for (k = 0 ; k < n ; k++)
    scanf ("%d",&A[k]);

  for (k = 0 ; k < n ; k++){
    printf ("%d",A[k]);
    if (k < n-1) printf (" ");
    else if (k == n-1) printf ("\n");
  }

  for (i = 1 ; i <= n-1 ; i++){
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for (k = 0 ; k < n ; k++){
      printf ("%d",A[k]);
      if (k < n-1) printf (" ");
      else if (k == n-1) printf ("\n");
    }
  }
  
  return 0;
}
