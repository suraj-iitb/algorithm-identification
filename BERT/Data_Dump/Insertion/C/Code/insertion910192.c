#include <stdio.h>
main(){
  
  int kosu,array[100],key;
  int i,j,k;
  
  scanf("%d",&kosu);
  
  for(i = 0 ; i < kosu ; i++){
    scanf("%d",&array[i]);
  }


  for(k = 0 ; k < kosu ; k++){
	printf("%d",array[k]);
	if(k < kosu - 1) printf(" ");
      }
      printf("\n");


  for(i = 1 ; i < kosu ; i++){

    key = array[i];

    j = i - 1;


    
    while((j >= 0) && (array[j] > key)){
      
      array[j + 1] = array[j];
      j--;
      
    }
    
    array[j + 1] = key;

         
      for(k = 0 ; k < kosu ; k++){
	printf("%d",array[k]);
	if(k < kosu - 1) printf(" ");
      }
      printf("\n");



  }
  
  
  return 0;

}
