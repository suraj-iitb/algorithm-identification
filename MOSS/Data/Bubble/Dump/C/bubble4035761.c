#include<stdio.h>
int bubbleSort(int* ,int);
int main(){
  int array[100],num,kai,i;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }
  kai = bubbleSort(array,num);
  for(i=0;i<num;i++){
    if(i!=0)printf(" ");
  printf("%d",array[i]);
  }
  printf("\n%d\n",kai);
  return 0;
}
int bubbleSort(int* A,int N){
  int flag =1,dai,kai=0,j;
    while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	dai=A[j];
	A[j]=A[j-1];
	A[j-1]=dai;
	kai++;
	flag=1;
      }
    }
  }
  return kai;
}

