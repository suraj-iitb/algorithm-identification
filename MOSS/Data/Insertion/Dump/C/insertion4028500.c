#include <stdio.h>
#define N 100

void printa(int *,int);

int main(){
  int a[N],i,j,v,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<n;i++){
    printa(a,n);
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
  }
  printa(a,n);
  return 0;
}

void printa(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
}

