
#include<stdio.h>
#define N 100

main(){
  int i,j,a[N],b,n,minj,count=0,c,d;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n-1;i++){
    minj = i;    
    for(j=i;j<n;j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    if(a[i]!= a[minj]){
    b = a[minj];
    a[minj] = a[i];
    a[i] = b;
    count++;
    }
  }
  
  printf("%d",a[0]);
  for(i=1;i<n;i++){
    printf(" %d",a[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
