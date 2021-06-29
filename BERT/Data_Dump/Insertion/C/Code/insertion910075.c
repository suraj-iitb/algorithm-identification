#include<stdio.h>
#define s 100
int main()
{
  int i,j,p,key,N,A[s];
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  for(i=0;i<N;i++){
    key=A[i];
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    for(p=0;p<N;p++){
      if(p>=1) printf(" ");
      printf("%d",A[p]); 
    }
    printf("\n");
  }
  return 0;
}
