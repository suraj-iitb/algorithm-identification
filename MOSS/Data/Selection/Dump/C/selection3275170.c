#include<stdio.h>

int main(){

  int n, i, j, min, tmp, cnt=0;

  scanf("%d", &n);

  int a[n];

  for(i=0;i<n;i++) scanf("%d", &a[i]);

  for(i=0;i<n-1;i++){

    min=i;

    for(j=i;j<n;j++){

      if(a[j]<a[min]) min=j;

    }

    if(a[i]!=a[min]){

      tmp=a[i];

      a[i]=a[min];

      a[min]=tmp;

      cnt++;

    }

  }

  for(i=0;i<n;i++){

    if(i==0) printf("%d", a[i]);

    else printf(" %d", a[i]);

  }

  printf("\n%d\n", cnt);

  return 0;

}

