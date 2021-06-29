#include <stdio.h>
main(){

  int i,j;
  int a[100],n,change,kaisu = 0;

  scanf("%d",&n);

  for(i = 0 ; i < n  ;i++){
    scanf("%d",&a[i]);
  }
  
  
  for(i = 0 ; i <= n - 1 ; i++){

    for(j = n - 1 ; j >= i + 1 ; j--){

      if(a[j] < a[j - 1]){

	change = a[j];
	a[j] = a[j - 1];
	a[j - 1] = change;

	kaisu++;

      }
    }
  }
  
  for(i = 0 ; i < n ; i++){
    if(i) printf(" ");
    printf("%d",a[i]);
  }

  printf("\n%d\n",kaisu);
  
  return 0;

}
