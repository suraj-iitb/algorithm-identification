#include<stdio.h>
static const int N = 100;

void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){

  int len,a[N+1],i,j,key=0;

  scanf("%d",&len);
  for(i=1;i<=len;i++){  
    scanf("%d",&a[i]);
  }
  
  trace(a,len);
  for(i=2;i<=len;i++){
    key=a[i];
    j=i-1;
    while(j>0 && a[j]>key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
    trace(a,len);
  } 
  return 0;
}
