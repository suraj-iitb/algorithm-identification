#include<stdio.h>
#include<stdlib.h>

int main(){
  
  int *A,key,i,j,tmp,mini,count=0;
  scanf("%d",&key);
  A = (int *)malloc(sizeof(int) * key);
  if(A == NULL){
    exit(0);
  }
  for(i=0;i<key;i++){
    A[i] = 0;
  }
  for(i=0;i<key;i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 0;i<key;i++){
    mini = i;
    for(j = i;j < key;j++){
      if(A[j] < A[mini]){
	mini = j;      
}
    }
      tmp = A[i];
      A[i] = A[mini];
      A[mini] = tmp;
      if(i!=mini)count++;
  }
  for(i=0;i<key;i++){ 
    if(i != key-1){
    printf("%d ",A[i]);
    }else{
      printf("%d\n%d\n",A[key-1],count);  
    }
  }
  free(A);
  
  return 0;
}
