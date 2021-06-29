#include<stdio.h>

int main(){
  int a , j, v, i;

  scanf("%d",&a);
  int A[a];

 for(i=0; i<a; i++){
  scanf("%d",&A[i]);
  }

   for(i=0; i<a; i++){
    printf("%d",A[i]);
    if(i<a-1) printf(" ");
  }
  printf("\n");
  
  for(i=1; i<=a-1; i++){
    v = A[i];
    j = i - 1;

    while((j >= 0) && (A[j] > v)){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }

    for(j=0; j<a; j++){
    printf("%d", A[j]);
    if(j<a-1) printf(" ");
  }
  printf("\n");
  }
  
  return 0;
}

