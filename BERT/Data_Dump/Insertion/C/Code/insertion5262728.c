#include<stdio.h>
#define N 101


int n;
int A[N];



void insertion(){

  int i,j,x;

  for(i=1;i<n;i++){
    j=i-1;
    x=A[i];
    while(j>=0 && x<A[j]){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=x;
    for(j=0;j<n;j++){
      if(j>0)printf(" ");
      printf("%d",A[j]);
    }
    printf("\n");
  }
}




int main(){

  int i,j;
  int x;




  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(j=0;j<n;j++){
    if(j>0)printf(" ");
    printf("%d",A[j]);

  }
  printf("\n");


  insertion();



  return 0;
}

