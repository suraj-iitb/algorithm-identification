#include<stdio.h>
#define M 1000

main(){
  int n,a[M],i,j,v;

    scanf("%d",&n);
      
  for( i=0 ; i<n ; i++ ) 
    scanf("%d",&a[i]);
   
   for( i=1 ; i<=n ; i++ ){
    for( j=0 ; j<n ; j++ ){
      printf("%d",a[j]);
      if(a[j+1] != '\0')
	printf(" ");
      else printf("\n");
    }
    v = a[i];
    j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    }
  return 0;
}
  
