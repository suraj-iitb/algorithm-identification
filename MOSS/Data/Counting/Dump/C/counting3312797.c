#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define M 10000

int main(){
  unsigned short *a,*c;
  int i,j,n,b[M+1],count=0;
  scanf("%d",&n);
  a=malloc(sizeof(short) * n+1);
  c=malloc(sizeof(short) * n+1);
  for(i=1;i<=n;i++){
    scanf("%hu",&a[i]);
  }
  for(i=0;i<=M;i++){
    b[i]=0;
  }
  for(j=1;j<=n;j++){
    b[a[j]]++;
    }
  for(i=1;i<=M;i++){
    b[i] = b[i] + b[i-1];
  }
   for(i=n;i>0;i--){
     c[b[a[i]]] = a[i];
     b[a[i]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",c[i]);
    if(i!=n)printf(" ");
    else printf("\n");
  }
  return 0;
}


