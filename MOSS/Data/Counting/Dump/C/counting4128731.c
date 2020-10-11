#include <stdio.h>
#include <stdlib.h>
int main(){
  int *a,*b;
  int c[10000],n,i;

  scanf("%d",&n);

  a=malloc(sizeof(int)*n+1);
  b=malloc(sizeof(int)*n+1);

  for(i=0;i<=10000;i++){
    c[i]=0;
  }

  for(i=0;i<=n-1;i++){
    scanf("%d",&a[i+1]);
    c[a[i+1]]++;
  }

  for(i=0;i<=10000;i++){
    c[i+1]=c[i]+c[i+1];
  }
  
  for(i=n;i>=1;i--){
    b[c[a[i]]]=a[i];
    c[a[i]]--;
  }

  for(i=1;i<=n;i++){
    printf("%d",b[i]);
    if(i!=n)printf(" ");
  }

  printf("\n");

  return 0;
}

