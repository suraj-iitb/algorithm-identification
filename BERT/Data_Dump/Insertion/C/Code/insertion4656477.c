#include<stdio.h>
#define N 1000

int main(){
  int i, j, k, n, key, line=1;
  int A[N];
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<=n;i++){
    for(j=0;j<n;j++){
      //if(j == line){
	
      //}
      if(j!=0){
	printf(" ");
      }
      printf("%d", A[j]);
      
    }
    
    printf("\n");
    

    key = A[i];
    k = i-1;
    while(k >=0 && A[k] > key){
      A[k+1] = A[k];
      k--;
    }
    A[k+1] = key;
    //line++;
  }


  return 0;
}


