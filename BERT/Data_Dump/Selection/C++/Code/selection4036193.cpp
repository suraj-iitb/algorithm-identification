#include<stdio.h>
int selectionSort(int* ,int);
int main(){
  int array[100],num,kai,i;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }
  kai = selectionSort(array,num);
  for(i=0;i<num;i++){
    if(i!=0)printf(" ");
    printf("%d",array[i]);
  }
  printf("\n%d\n",kai);
  return 0;
}
int selectionSort(int*A,int N){
  int j,minj,dai,i,kai=0;
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j] < A[minj]){
	minj=j;
      }
    }
    dai=A[i];
    A[i]=A[minj];
    A[minj]=dai;
    if(dai!=A[i])kai++;
  }
  return kai;
}

