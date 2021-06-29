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
    int left = 0, right = n1 + 1, mid;
    mid = (left + right) / 2;
    while( left < right ){
      if( array2[i] == array1[mid] || array2[i] == array1[left] || array2[i] == array1[right]){
	count++;
	break;
      }else if( array2[i] > array1[mid]){
	left = mid + 1;
	mid = (left + right) / 2;
      }else{
	right = mid;
	mid = (left + right) / 2;
      }		
    }
  }
  
  printf("%d\n", count);
  
  return 0;
}
 
