#include<stdio.h>

int main(){

  int n, cnt=0, i, j, k, tmp;

  scanf("%d", &n);

  int a[n];

  for(i=0;i<n;i++) scanf("%d", &a[i]);

  for(i=0;i<n;i++){

    for(j=n-1;j>i;j--){

      if(a[j]<a[j-1]){

	tmp=a[j];

	a[j]=a[j-1];

	a[j-1]=tmp;

	cnt++;

      }

    }
    
  }

  for(i=0;i<n;i++){

    if(i==0) printf("%d", a[i]);

    else printf(" %d", a[i]);

  }

  printf("\n%d\n", cnt);

  return 0;

}

