#include<stdio.h>

main(){
  int n1, count = 0;
  scanf("%d", &n1);

  int i, j, array1[n1];
  for( i = 0; i < n1; i++){
    scanf("%d", &array1[i]);
  }
  int n2;
  scanf("%d", &n2);
  int array2[n2+1];
  for( i = 0; i < n2; i++){
    scanf("%d", &array2[i]);
  }
  
  for( i = 0; i < n2; i++){
    for( j = 0; j < n1; j++){
      if( array2[i] == array1[j]){
	count++;
	break;
      }
    }
  }
  
  printf("%d\n", count);
  
  return 0;
}
