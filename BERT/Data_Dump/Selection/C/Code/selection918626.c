#include<stdio.h>
#define N 100

void trace(int a[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
}

int main(void){
  int n,i,j,sw,judge,mini,co=0,a[N];
  
  scanf("%d",&n);  
  for ( i = 1; i <= n; i++ ) scanf("%d", &a[i]);
  
  for(i=1; i<n+1; i++){
    judge=0;
    mini=i;
    for(j=i; j<n+1; j++){
      if(a[j]<a[mini]){
	mini=j;
	judge=1;
      }
    }
    if(judge==1){
      sw=a[mini];
      a[mini]=a[i];
      a[i]=sw;
      co++;
    }
  }
  
  trace(a,n);
  printf("%d\n",co);
  return 0;
}
