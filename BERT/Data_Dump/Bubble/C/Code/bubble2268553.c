#include <stdio.h>
#include <stdlib.h>
#define N 100

void swap(int *,int *);
void BubbleSort(int *,int);

int main(){
  int a,*number,i;
  scanf("%d",&a); 

  number = (int*)malloc(a*sizeof(int));
  for(i = 0;i < a;i++){
    scanf("%d",&number[i]);
  }
  BubbleSort(number,a);
  free(number);
  return 0;
}

void swap(int *a,int *b){
  int temp;
  
  temp = *a;
  *a = *b;
  *b = temp;
}

void BubbleSort(int *num,int a){
  int i,j,cnt=0;

  for(i = 0;i < a-1;i++){
    for(j = a-1;j > i;j--){
      if(num[j-1] > num[j]){
	swap(&num[j],&num[j-1]);
	cnt++;
      }
    }
    printf("%d ",num[i]);
  }
  printf("%d\n",num[a-1]);
  printf("%d\n",cnt); 
}
