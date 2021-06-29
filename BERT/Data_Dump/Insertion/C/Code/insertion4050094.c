#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[n], i, j, k, tmp;
  for (i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }
  
  for (k=0; k<n; k++) {
    if (k<n-1) {
      printf("%d ", arr[k]);
    } else {
      printf("%d\n", arr[k]);
    }
  }

  for (i=1; i<n; i++) {
    for (j=i; j!=0 && arr[j-1]>arr[j]; j--) {
      tmp=arr[j];
      arr[j]=arr[j-1];
      arr[j-1]=tmp;
    }

    for (k=0; k<n; k++) {
      if (k<n-1) {
        printf("%d ", arr[k]);
      } else {
        printf("%d\n", arr[k]);
      }
    }
  }
  return 0;
}
