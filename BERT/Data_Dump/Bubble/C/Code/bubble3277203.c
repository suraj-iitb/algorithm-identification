#include<stdio.h>
void bubbleSort(int[],int);

int main(){
  int A[100],n,i,j;

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  bubbleSort(A,n);

  return 0;
}

void bubbleSort(int a[], int n){
  int count=0,flag=1,i,j,temp;
  
  for(i = 0 ; flag ; i++){
    flag = 0;
      for(j = n - 1 ; j >= i+1 ; j--){
      if (a[j] < a[j-1]){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	flag = 1;
	count++;
      }
    }
  }

  for(i = 0 ; i < n ; i++){
    if(i > 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",count);
}
      
  

