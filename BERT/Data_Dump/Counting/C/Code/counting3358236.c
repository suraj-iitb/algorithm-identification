#include <stdlib.h>
#define MAX 2000005
#define VMAX 10005

int A[MAX], B[MAX];
int C[VMAX+1];

int main(){
  

  int n, i, j;

  scanf("%d", &n);



  for(i=1;i<=n;i++){
       scanf("%d",A+i);
   
  }
  
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
 
  for(i=1;i<=VMAX;i++){
    C[i] += C[i-1];
  }
 
  
  for(j=n;j>0;j--){
    B[C[A[j]]]= A[j];
    C[A[j]]--;
  }
    
  for(j=1;j<=n;j++){
    printf("%d",B[j]);
    if(j!=n)printf(" ");
  }
  printf("\n");
  
  return 0;
}

