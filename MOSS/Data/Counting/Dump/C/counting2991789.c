#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int main(){
  int *A,*B;
  int C[MAX+1];
  int n,i;

  scanf("%d",&n);
  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);

  for(i=0;i<=MAX;i++) C[i]=0;

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

  for(i=1;i<=MAX;i++) C[i]=C[i]+C[i-1];

  for(i=1;i<=n;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }

  for(i=1;i<=n;i++){
    if(i > 1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;

}

/*#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
 
int main(){
  int *A,*B;
  int C[MAX+1];
  int n,i;
 
  scanf("%d",&n);
  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);
 
  for(i=0;i<=MAX;i++) C[i]=0;
 
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }
 
  for(i=1;i<=MAX;i++) C[i]=C[i]+C[i-1];
 
  for(i=1;i<=n;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
 
  for(i=1;i<=n;i++){
    if(i > 1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
 
  return 0;
 
}*/

