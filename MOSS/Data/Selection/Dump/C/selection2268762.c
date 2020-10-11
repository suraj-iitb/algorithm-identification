#include <stdio.h>

#define N 100

int count = 0;

void selectionSort(int *,int);
void swap(int *,int *);

int main(){
  int length,A[N],i;

  while(1){
    scanf("%d",&length);
    if(1 <= length && length <= 100) break;
  }

  for(i = 0;i < length;i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || 100 < A[i]) i = i - 1;
  }
  selectionSort(A,length);

  for(i = 0;i < length - 1;i++) printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}

void selectionSort(int *p,int l){
  int i,j,minj;
  for(i = 0;i < l;i++){
    minj = i;
    for(j = i;j < l;j++){
      if(p[j] < p[minj]) minj = j;      
    }
    swap(&p[i],&p[minj]); 
    if(i != minj) count++;
  }
}

void swap(int *q,int *r){
  int tmp;
  tmp = *q;
  *q = *r;
  *r = tmp;
}
