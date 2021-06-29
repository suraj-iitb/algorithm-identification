#include<stdio.h>
void selectionSort(int[],int);

int main(){
  int A[100],n,i;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,n);

  return 0;
}

void selectionSort(int a[], int n){
  int count=0,i,j,minj,temp;

  for(i = 0 ; i < n - 1 ; i++){
    minj = i;
    for(j = i ; j < n ; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
      temp = a[i];
      a[i] = a[minj];
      a[minj] = temp;
      if(i != minj) count++;
  }
  
  for(i = 0 ; i < n ; i++){
    if(i > 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",count);
}
