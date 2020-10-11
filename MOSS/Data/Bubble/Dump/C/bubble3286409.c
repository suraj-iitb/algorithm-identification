#include <stdio.h>

int main () {
  int len,i,j,tmp,k=0;
  int ar[1000];
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&ar[i]);
  }
  for (i = len - 2; i >= 0; i--)
    for (j = 0; j <= i; j++)
      if (ar[j] > ar[j + 1]) {
        tmp = ar[j]; ar[j] = ar[j + 1]; ar[j + 1] = tmp;
        k++;
      }
  for (i = 0; i < len-1; i++) {
    printf("%d ", ar[i]);
  }
  printf("%d",ar[len-1]);
  printf("\n");
  printf("%d\n",k);

  return 0;
}
