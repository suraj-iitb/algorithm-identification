#include <stdio.h>
#define N 100

int main(){
  int i,j,n,tmp,count=0;
  int a[N];
  
  scanf("%d",&n);
  for( i=0 ; i<n ; i++ ){
    scanf("%d",&a[i]);
  }

  for( i=n-1 ; i>=1 ; i-- ){
    for( j=n-1 ; j>=1 ; j-- ){
      if(a[j] < a[j-1]){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	count++;
      }
    }
  }
  
  for( i=0 ; i<n ; i++ ){
    if( i == n-1 ){
      printf("%d\n",a[i]);
    }
    else{
      printf("%d ",a[i]);
    }
  }
  
  printf("%d\n",count);
  

return 0;
}
