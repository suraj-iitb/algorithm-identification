#include <stdio.h>
#define N 100

int main(){
  int key,i,j,k,num;
  int A[N];
  scanf("%d",&num);
  for(i=0;i<num;i++)scanf("%d",&A[i]);

  for(k=0;k<num;k++){
    printf("%d",A[k]);
    if(k!=num-1) printf(" ");
  }
  printf("\n");
  
  for(i=1;i<num;i++){
    key=A[i];
    j=i-1;
    
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    for(k=0;k<num;k++){
      printf("%d",A[k]);
      if(k!=num-1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
