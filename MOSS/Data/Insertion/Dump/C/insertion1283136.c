#include<stdio.h>
#define AMAX 1000

void insertionSort(int *,int); 

main(){
  
  int i,n,num[AMAX],x /* xは要素数 */;
  
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
    
    scanf("%d",&num[i]);
    
  }
  
  x = i;

  insertionSort(num,x);

    for(i = 0 ; i < x ; i++){
      printf("%d",num[i]);
      if(i != x-1)printf(" ");
    }

    printf("\n");

  return 0;
}

void insertionSort(int *num, int x){

  int i,j,k,key;


  for(i = 1 ; i <= x-1 ; i++){

    for(k = 0 ; k < x ; k++){
      printf("%d",num[k]);
      if(k != x-1)printf(" ");
    }

   printf("\n");


    key = num[i];
    j = i-1;

    while(j >= 0 && num[j] > key){

      num[j+1] = num[j];
      j--;
    }

    num[j+1] = key;

  }
  
}
