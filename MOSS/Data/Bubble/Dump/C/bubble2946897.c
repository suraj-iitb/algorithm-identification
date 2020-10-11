#include <stdio.h>

int main(){
  int n, a[100], i, count=0, flag=1, b;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  while(flag==1){
    flag=0;
    for(i=n-1; i>0; i--){
      if(a[i]<a[i-1]){
	b=a[i];
	a[i]=a[i-1];
	a[i-1]=b;
	count++;
	flag=1;
      }
    }
  }

  for(i=0; i<n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d",a[n-1]);
  printf("\n%d\n", count);
  return 0;
}

