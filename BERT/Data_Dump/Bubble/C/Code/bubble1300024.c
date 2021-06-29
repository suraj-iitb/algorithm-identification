#include<stdio.h>
#define N 100
main(){
  int i,j,n,a[N],count=0,b;

  scanf("%d",&n);
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(a[j] < a[j-1]){
	b = a[j-1];
	a[j-1] = a[j];
	a[j] = b;
	count++;
      }
    }
  }
  printf("%d",a[0]);
  for(i=1;i<n;i++){
  printf(" %d",a[i]);
  }
  printf("\n");
  printf("%d\n",count);
    return 0;
}

  
