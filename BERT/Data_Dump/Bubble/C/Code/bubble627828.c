#include <stdio.h>
#define MAX 100

int BubbleSort(int [],int);

int main(void){

  int i,len;
  int chenge;
  int A[MAX];


  scanf("%d",&len);

  for(i=0;i<len;i++)
    scanf("%d",&A[i]);

  chenge = BubbleSort(A,len);

  for(i=1;i<len;i++)
    printf("%d ",A[i-1]);
  printf("%d\n",A[i-1]);

  printf("%d\n",chenge);
  return 0;
}


int BubbleSort(int A[],int len){
  
  int i,j;
  int chenge=0;
  int tmp;
  
  for(i=0;i<len;i++){
    for(j=len-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
	tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	chenge++;
      }
    }
  }

  return chenge;
}
