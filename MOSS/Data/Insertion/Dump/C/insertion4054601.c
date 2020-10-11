#include<stdio.h>
#define MAX 1000


int main(){
  int i,j,A[MAX],n,key;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  for(i=1;i<n;i++){
    for(j=0;j<n;j++){
      if ( j != 0 ) printf(" ");
      printf("%d",A[j]);
    }
    printf("\n");
    key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
  }
  
  for(j=0;j<n;j++){
    if ( j != 0 ) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n");
  
  return 0;
}

