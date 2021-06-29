#include<stdio.h>
#include<stdlib.h>

#define NMIN 1
#define NMAX 100
#define AMIN 1
#define AMAX 100
int main(){
  int N,A[NMAX],i,j,subA,cnt=0,minj;
  scanf("%d",&N);
  if(N<NMIN||N>NMAX) exit(1);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<N;i++){
 minj = i;
    for(j=i; j<N; j++)
      if(A[j] < A[minj]) {
	minj = j;
      }
    if(minj!=i){
    subA = A[i];
    A[i] = A[minj];
    A[minj] = subA;
    cnt++;
      }
  }
   for(i=0;i<N;i++){
       if(i==N-1)
     printf("%d\n",A[i]);
     else
     printf("%d ",A[i]);
   }
  printf("%d\n",cnt);
  return 0;
}

