#include <stdio.h>
#define N 101

int main(){
  int i,j,n,A[N],minj,temp,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);


  //selectionsort 
  
  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if (A[j] < A[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      c=c+1;
      
    }
  }
  
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

