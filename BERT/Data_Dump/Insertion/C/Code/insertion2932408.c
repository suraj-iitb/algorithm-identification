#include <stdio.h>

void print(int n,int a[]){

  int i;
  for(i=0;i<n;i++){

    if(i) printf(" ");
    printf("%d",a[i]);

  }

  puts("");

}

int main(){

  int n,i;
  int a[1000];

  scanf("%d",&n);

  for(i=0;i<n;i++) scanf("%d",&a[i]);

  for(i=0;i<n;i++){

    int v=a[i];
    int j=i-1;

    for(;j>=0 && a[j]>v;j--) a[j+1]=a[j];

    a[j+1]=v;

    print(n,a);

  }

  return 0;

}

