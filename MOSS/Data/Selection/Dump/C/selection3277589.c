#include<stdio.h>
#define N 100

int main(){
  int n, a[N], min, v, cnt = 0;
  int i, j;
  
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }

  for(i=0;i<=n-1;i++){
    min = i;
    for(j=i;j<=n-1;j++){
      if(a[j] < a[min]){
	min = j;
      }
    }
    v = a[i];
    a[i] = a[min];
    a[min] = v;
    if(i != min) cnt++;
  }

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d\n", a[i]);
    else printf("%d ", a[i]);
  }

  printf("%d\n", cnt);
  
  return 0;
}

