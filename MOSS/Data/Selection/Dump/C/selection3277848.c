#include<stdio.h>
#define N 100

int main(){
  int A[N];
  int i,j,k,n,num,minj,temp;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i <= n-1; i++){

    minj = i;
    
    for(j = i; j <= n-1; j++){

      if(A[j] < A[minj]){
	minj = j;
      }
      
    }//for

    if(i != minj){
      
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      num++;
    
    }
    

  }//for

  for(k=0;k<n;k++){

    printf("%d",A[k]);
    if(k!=n-1)printf(" ");
    else printf("\n");
    
  }

  printf("%d\n",num);

  return 0;
  
}

