#include <stdio.h>
#define N 100

int main(){
  int i,j,n,minj,flag =0,tmp,count=0;
  int a[N];
  
  scanf("%d",&n);
  for( i=0 ; i<n ; i++ ){
    scanf("%d",&a[i]);
  }

  for( i=0 ; i<=n-1 ; i++ ){
    minj = i;
    for( j=i ; j<=n-1 ; j++ ){
      if( a[j] < a[minj] ){
	minj = j;
	if(flag == 0){
	  flag = 1;
	  count++;
	}
      }
    }
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;

    flag = 0;
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
