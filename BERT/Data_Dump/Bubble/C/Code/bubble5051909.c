#include <stdio.h>
int main(void){
  int i, j, n, count=0, temp, a[100];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(i=0; i<n; i++){
    for(j=n-1; i<j; j--){
      if(a[j-1]>a[j]){
        temp=a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        count++;
      }
    }
  }

  for(i=0; i<n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], count);

  return 0;
}

