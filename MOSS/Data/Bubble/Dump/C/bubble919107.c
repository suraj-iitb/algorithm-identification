#include <stdio.h>

void bubble(int n,int A[]);

int count=0;

main(){
  
  int n,i,j,A[1000];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  bubble(n,&A[0]);

  for(i=0;i<n;i++){
  if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
  
  return 0;
}

void bubble(int n,int A[]){
  int i,j;
  int key;
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j] < A[j-1]){
	key = A[j];
	A[j] = A[j-1];
	A[j-1] = key;
	++count;
      }
    }
  }
return 1;
}
