#include<stdio.h>
int main(){
  int a=0;
  int N=0;
  int A[100];
  int i=0;
  int j=0;
  int temp=0;
  int p;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(i==N-1) printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");
  for(i=1;i<N;i++){
    temp=A[i];
    j=i-1;
    while(j>=0&&A[j]>temp){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=temp;
    
    for(a=0;a<N;a++){
      if(a==N-1) printf("%d",A[a]);
      else printf("%d ",A[a]);
      
    }
    printf("\n");
  }
  return 0;
}


