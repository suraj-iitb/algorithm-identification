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
  int n,i,j,sw,co=0,a[N];
  
  scanf("%d",&n);  
  for ( i = 1; i <= n; i++ ) scanf("%d", &a[i]);

  for(i=1;i<n+1;i++){
    for(j=n; j>i; j--){
      if(a[j]<a[j-1]){
	sw=a[j];
	a[j]=a[j-1];
	a[j-1]=sw;
	co++;
      }
    }
  }
  trace(a,n);
  printf("%d\n",co);

  return 0;
}
