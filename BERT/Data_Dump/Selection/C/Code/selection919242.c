#include <stdio.h>

void SelectionSort(int n,int A[]);

int count=0;

main(){
  
  int n,i,j,A[100];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  SelectionSort(n,&A[0]);

  for(i=0;i<n;i++){
    if(i !=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
  
  return 0;
}

void SelectionSort(int n,int A[]){
  int i,j;
  int mini,key;
  
  for(i=0;i<n;i++){
    mini = i; 
    for(j=i+1;j<n;j++){
      if(A[j] < A[mini]){
	mini = j;
      }
    }
    if(mini != i){
      key = A[i];
      A[i] = A[mini];
      A[mini] = key;
      ++count;
    }
  }
}
