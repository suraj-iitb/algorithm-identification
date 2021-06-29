#include <stdio.h>
main(){

  int i,j;
  int a[100],n,mini,kaisu = 0,c;

  scanf("%d",&n);

  for(i = 0 ; i < n  ;i++){
    scanf("%d",&a[i]);
  }
  
  
  for(i = 0 ; i <= n - 1 ; i++){
    mini = i;
    for(j = i ; j <= n - 1 ; j++){

      if(a[j] < a[mini]){

	mini = j;
	
      }
    }
    if(mini != i) {
    c = a[i];
    a[i] = a[mini];
    a[mini] = c;
    kaisu++;
    }
  }
  
  for(i = 0 ; i < n ; i++){
    if(i) printf(" ");
    printf("%d",a[i]);
  }

  printf("\n%d\n",kaisu);
  
  return 0;

}
