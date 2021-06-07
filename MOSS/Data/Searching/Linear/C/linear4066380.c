#include<stdio.h>

#define N 10000

int main(){

  int n,i,j,q,count=0;
  int a[N],b[N];

  scanf("%d",&n);
  for( i= 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&q);
  for( i = 0 ; i < q ; i++){
    scanf("%d",&b[i]);
    for( j = 0 ; j < n ; j++){
      if(b[i] == a[j]){
         count++;
	 break;
      }
    }      
  }

  printf("%d\n",count);
  return 0;

}

