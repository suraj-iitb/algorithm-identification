#include<stdio.h>
#define N 100
void swap(int *,int *);

int main(){
  int flag,i,j,n,count=0,minj;
  int A[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-1;i++){
    minj = i;
    
    for(j=i;j<=n-1;j++){
      
      if (A[j] < A[minj]){
	minj = j;
      }

    }
    if(i!=minj){
    swap(&A[i],&A[minj]);
    count++;
    }
  }
  
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

void swap(int *a,int *b){
  int temp;
  
  temp = *a;
  *a=*b;
  *b=temp;
}

