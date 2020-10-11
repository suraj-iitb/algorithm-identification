#include <stdio.h>
#define N 100

int main(){
  int A[1001];
  int i,j,k,num,temp;

  scanf("%d",&num);
  for(i=0; i<num; i++){
    scanf("%d",&A[i]);
  }

  for(j=1; j<=num-1; j++){
    for(k=0; k<=num-1; k++){
      printf("%d",A[k]);
      if(k != num-1) printf(" ");
      else printf("\n");
    }

    
    temp = A[j];
    i = j-1;
    while(i>=0 && A[i]>temp){
      A[i+1] = A[i];
      i--;
    }
    A[i+1] = temp;
  }
  for(k=0; k<=num-1; k++){
    printf("%d",A[k]);
    if(k != num-1) printf(" ");
    else printf("\n");
  }
  
  return 0;
}

