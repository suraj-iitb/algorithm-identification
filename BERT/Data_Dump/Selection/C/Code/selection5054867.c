#include <stdio.h>

int selectionSort(int A[],int n);

int main(){

  int A[100];
  int n,i,c;

  i=0;
  while(1){
    scanf("%d",&n);
    if(1<=n&&n<=100){
      while(1){
	if(n==i) break;
	scanf("%d", &A[i]);
	if(0<=A[i]&&A[i]<=100) i++;
      }
      break;
    }
  }

  c=selectionSort(A,n);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}

int selectionSort(int A[],int n){
  int i,j,c=0,t,min;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[min]>A[j]) min=j;
    }
    if(A[min]!=A[i]){
      t=A[i];
      A[i]=A[min];
      A[min]=t;
      c++;
    }
  }
  return c;
}

