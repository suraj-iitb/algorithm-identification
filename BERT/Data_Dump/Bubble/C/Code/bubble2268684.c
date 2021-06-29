#include <stdio.h>

#define N 100

int count = 0;

void bubbleSort(int *,int);
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
  bubbleSort(A,length);

  for(i = 0;i < length - 1;i++) printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}

void bubbleSort(int *p,int l){
  int flag = 1;
  int i = 0,j;
  while(flag){
    flag = 0;
    for(j = l - 1;j >= 1;j--){
      if(p[j] < p[j-1]){
	swap(&p[j],&p[j-1]);
	flag = 1;
      }
      i++;
    }
  }
}

void swap(int *q,int *r){
  int tmp;
  tmp = *q;
  *q = *r;
  *r = tmp;
  count++;
}
