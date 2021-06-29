#include<stdio.h>
#include<stdlib.h>
#define Max 10000

int main(){
  int *a,*b;

  int c[Max+1];
  int n,i,j;
  scanf("%d",&n);

  a=malloc(sizeof(int)*n+1);
  b=malloc(sizeof(int)*n+1);

  for(i=0;i<=Max;i++)c[i]=0;
  for(i=0;i<n;i++){
    scanf("%d",&a[i+1]);
    c[a[i+1]]++;
  }
  for(i=1;i<=Max;i++)c[i]=c[i]+c[i-1];
  for(j=1;j<=n;j++){
    b[c[a[j]]]=a[j];
    c[a[j]]--;
  }

  for(i=1;i<=n;i++){
    if(i>1)printf(" ");
    printf("%d",b[i]);
  }
  printf("\n");
  return 0;
}

