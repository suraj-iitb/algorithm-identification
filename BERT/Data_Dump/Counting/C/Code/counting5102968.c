#include<stdio.h>
#define N 10000
int A[2000001],O[N],B[2000001];

int main()
{
  int i,n;
 
  scanf("%d",&n);
  
  for(i=1;i<n+1;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    O[i]=0;
  }
  
  for(i=1;i<n+1;i++){
    O[A[i]]+=1;
  }
  
  for(i=0;i<N;i++){
    O[i]+=O[i-1];
  }
  
  for(i=n+1;i>0;i--){
    B[O[A[i]]]=A[i];
    O[A[i]]-=1;
  }

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d",B[i]);
  printf("\n");
  return 0;
}
