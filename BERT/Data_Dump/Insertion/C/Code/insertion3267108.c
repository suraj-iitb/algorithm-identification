#include <stdio.h>

int main(){
  int arr[100],n,i,j,k,key;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    if(i>0) printf(" ");
    printf("%-d",arr[i]);
  }
  printf("\n");

  for(i=1;i<n;i++){
    
    key = arr[i];
    j = i-1;

    
    for(k=0;k<n;k++){
     
      while(j >= 0 && arr[j] > key){
	arr[j+1] = arr[j];
	j--;
      }
      arr[j+1] = key;
      
      if(k>0) printf(" ");
      
      printf("%-d",arr[k]);

    }
    
    printf("\n"); 
  }

  
  return 0;
}

