#include<stdio.h>
#include<stdlib.h>
#define N 2000001
#define A 10001

int main(){

  int *a,*b;
  int cnt[A];
  int n,i,j;
  scanf("%d",&n);
  
  a = malloc(sizeof(int)*n+1);
  b = malloc(sizeof(int)*n+1);
  
  for(i=0; i<A; i++){
    cnt[i]=0;
  }

  for(i=0; i<n; i++){
    scanf("%d",&a[i+1]);
    cnt[a[i+1]]++;
  }

  for(i=1; i<A; i++){
    cnt[i]=cnt[i]+cnt[i-1];
  }
  for(j=1; j<=n; j++){
    b[cnt[a[j]]] = a[j];
    cnt[a[j]]--;
  }

  for(i=1; i<=n; i++){
    if(i>1){
      printf(" ");
    }
    printf("%d",b[i]);
  }
  printf("\n");

  return 0;
}
