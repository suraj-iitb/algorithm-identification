#include<stdio.h>

main(){

  int i,j,k,n,key,length[100];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&length[i]);
  }

  for(i = 0; i < n; i++){
    if(i < n-1){
      printf("%d ",length[i]);
    } else {
      printf("%d\n",length[i]);
    }
  }

  for(i = 1 ; i < n; i++){
    key = length[i];
    j = i - 1;
  
  while(j >= 0 && length[j] > key){
      length[j+1] = length[j];
      j = j - 1;
      length[j+1] = key;
    } 

    for(k = 0; k < n; k++){
      if(k < n-1){
	printf("%d ",length[k]);
      } else {
	printf("%d",length[k]);
      }
    }

    printf("\n");

  }
  return 0;
}
