#include<stdio.h>

main(){
  int key;
  int A[100];
  int i,j,a,l;

    scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }


  for(i=0;i<a;i++){
    key = A[i];
    j=i-1;
    
    while(j >= 0 && A[j] > key){
      A[j+1]=A[j];
      j--;
    }
    
    A[j+1]=key;
    
    
 for(l=0;l<a;l++){
   printf("%d",A[l]);
   if(l == a-1)break;
   printf(" ");
 }
   printf("\n");
   
  }
    return 0;
}
