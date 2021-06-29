#include<stdio.h>
main(void){
  int N,i,j,a[101],k,key;

 
  scanf("%d",&N);
  for(k=0;k<N;k++){
    scanf("%d",&a[k]);
  }
  
  for(i=0;i<=N-1;i++){
    if(i==N-1){
      printf("%d",a[i]);
    }
    else{
    printf("%d ",a[i]);
    }
  }
  printf("\n");
  
  for(i=1;i<=N-1;i++){
    key = a[i];
    j=i-1;
    while(j >= 0 && a[j]>key){
      a[j+1]=a[j];
      j--;
      a[j+1]=key;

      
    }
     for(k=0;k<N;k++){
       if(k==N-1){
	 printf("%d",a[k]);
       }
       else{
	printf("%d ",a[k]);
      }
     }
      printf("\n");
  }

  return 0;
}
