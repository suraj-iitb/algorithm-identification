/*選択ソート*/
#include <stdio.h>
#define N 100
int main(){
  int a[N], n, i, j, count=0, mini, tmp;

  scanf("%d", &n);

  for (i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for (i=0; i<n; i++){
    mini = i;
    for (j=i; j<n; j++){
      if (a[j]<a[mini]){
	mini = j;
      }
    }
    if (i != mini){
      tmp = a[i];
      a[i] = a[mini];
      a[mini] = tmp;
      count++;
    }
  }

  

  for (i=0; i<n; i++){
    if (i==n-1){
      printf("%d\n", a[i]);
      break;
    }
    printf("%d ", a[i]);
  }

  printf("%d\n", count);

  return 0;
}
  

