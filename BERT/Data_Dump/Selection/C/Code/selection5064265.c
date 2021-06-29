#include<stdio.h>
#define N 100

void SelectionSort(int *,int);
void swap(int *,int *);

int time = 0;

int main(){
  int A[N];
  int i,j,length;

  scanf("%d",&length);
  for(i=0;i<length;i++) scanf("%d",&A[i]);

  SelectionSort(A,length);

  for(i=0;i<length-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",time);

  return 0;
}

void SelectionSort(int *A,int n){
  int i,j,k;
  int mini;
  
  for(i=0;i<=n-1;i++){
    mini = i;
    for(j=i;j<=n-1;j++){
      if(A[j] < A[mini])
	mini = j;
    }
    if(A[i]>A[mini]){
      swap(&A[i],&A[mini]);
      time++;
    }
     
  }
  }
void swap(int *a,int *b){
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

  

