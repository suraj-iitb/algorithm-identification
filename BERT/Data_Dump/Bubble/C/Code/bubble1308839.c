#include<stdio.h>

void bubbleSort(int *,int);
#define N 100

int main(void){
  int i,n,A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(&A,n);
 
  return 0;
}

void bubbleSort(int *a,int k){
  int i,j,con=0,temp;
  for(i=0;i<k-1;i++){
    for(j=k-1;j>=i+1;j--){
      if(a[j] < a[j-1]){
	temp = a[j];
	a[j]=a[j-1];
	a[j-1] = temp;
	con++;
      }    
    }
  }
  for(i=0;i<=k-2;i++) { 
   printf("%d ",a[i]);
      }
  printf("%d\n",a[k-1]);
  printf("%d\n",con);
}
