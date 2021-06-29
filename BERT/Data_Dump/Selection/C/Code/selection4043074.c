#include<stdio.h>



int main(){
  int i,n,j,a,A[100],c= 0,k;


  
  scanf("%d",&a);

  
  for(i = 0; i < a; i++){
    scanf("%d",&A[i]);
  }


  
  for(i = 0; i < a; i++){

    n = i;
    
    for(j = i; j < a; j++){
      if(A[j] < A[n]) {
          
	n = j;
	
      }
    }
    if(n != i) c++;
    
    k = A[i];
    A[i] = A[n];
    A[n] = k;
    
  }

  
  for(i = 0; i < a; i++){
    printf("%d",A[i]);
    if(i == a -1) break;
    printf(" ");
  }

  
  printf("\n");
  printf("%d\n",c);
  return 0;
}

