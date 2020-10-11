#include<stdio.h>
#define N 100

int main(){
  int n, a[N], f = 1, v, cnt = 0;
  int i;
  
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &a[i]);
  }

  while(f){
    f = 0;
    for(i=n-1;i>=1;i--){
      if(a[i] < a[i-1]){
	v = a[i];
	a[i] = a[i-1];
	a[i-1] = v;
	f = 1;
	cnt++;
      }
    }
  }

  for(i=0;i<n;i++){
    if(i == n-1) printf("%d\n", a[i]);
    else printf("%d ", a[i]);
  }
  printf("%d\n", cnt);
  
  return 0;
}

