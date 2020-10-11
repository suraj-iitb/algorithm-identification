#include<stdio.h>
void CountingSort(int A[],int B[],int k){
  int x,y;
  int C[20000];

  
  for(x=0;x<20000;x++) C[x]=0;
  for(x=0;x<k;x++) C[A[x]+1]++;
  for(x=1;x<20000;x++){
    C[x]=C[x]+C[x-1];
  }

  for(x=1,k=0;x<=10001;x++){
    for(y=C[x-1];y<C[x];y++){
      B[k]=x-1;
      k++;
    }
  }
}


int A[2000000+1];
int B[2000000+1];
int main(void){
  int x,n;
  
  scanf("%d\n",&n);
  for(x=0;x<n;x++){
    scanf("%d",&A[x]);
  }
  
  CountingSort(A,B,n);
  
  for(x=0;x<n;x++){
    printf("%d",B[x]);
    if(x<n-1){
      printf(" ");
    } else{
      printf("\n");
    }
  }
  
  return 0;
}

