#include<stdio.h>

int main(){

  int i, j, k, n, key;

  scanf("%d", &n);

  int a[n];

  for(i=0;i<=n-1;i++){

    scanf("%d", &a[i]);

  }

  for(i=0;i<=n-1;i++){

    if(i==0) printf("%d",a[i]);

    else printf(" %d", a[i]);

  }printf("\n");

  for(i=1;i<=n-1;i++){

    key=a[i];

    j=i-1;

    while(j>=0 && a[j]>key){

      a[j+1] = a[j];

      j--;

    }

    a[j+1] = key;

    for(k=0;k<=n-1;k++){

      if(k==0) printf("%d",a[k]);

      else printf(" %d", a[k]);

    }printf("\n");

  }

  return 0;

}

