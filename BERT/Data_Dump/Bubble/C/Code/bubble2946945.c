#include<stdio.h>
#include<stdlib.h>
#define NMIN 1
#define NMAX 100
#define AMIN 0
#define AMAX 100

int main(){
  int N,A[NMAX],i,flag=1,subA,cnt=0;
  scanf("%d",&N);
  if(N<NMIN||N>NMAX) exit(1);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(A[i]<AMIN||A[i]>AMAX) exit(1);
  }
  
  while(flag){
    flag=0;
    for(i=N-1;i>=1;i--){
      if(A[i]<A[i-1]){
	subA=A[i];
	A[i]=A[i-1];
	A[i-1]=subA;
	cnt++;
	flag=1;
      }
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

