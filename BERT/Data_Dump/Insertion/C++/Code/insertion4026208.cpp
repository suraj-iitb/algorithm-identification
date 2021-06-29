#include<stdio.h>
#include<stdlib.h>
void insertionSort(int,int*);
int main(){
  int i,j,array[100];
  scanf("%d",&i);
  for(j=0;j<i;j++){
    scanf("%d",&array[j]);
    //printf("array[%d],%d\n",j,array[j]);
    if(i<1 && i>100 && array[j]<0 && array[j]>1000)exit(0);
    //printf("j=%d",j);
  }
  insertionSort(i,array);
  return 0;
}
void insertionSort(int p, int* A){
  int j,v,k,i;
  for(k=0;k<p;k++){
    if(k>0) printf(" ");
    printf("%d",A[k]);
  }
  printf("\n");
  for(i=1; i <=p-1;i++){
    v = A[i];
    j = i-1;
    while(j>=0&&A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(k=0;k<p;k++){
      if(k>0) printf(" ");
      printf("%d",A[k]);
    }
    printf("\n");
  }
}

