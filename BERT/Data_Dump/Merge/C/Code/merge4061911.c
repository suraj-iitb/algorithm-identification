#include <stdio.h>

#define HUGE 1000000001  /*define array's keeper*/
void  mergesort(int *,int,int);
void merge(int * , int ,int,int);
int count=0;
int main(){
  int num,array[500000],i;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }
  mergesort(array,0,num);

  for(i=0;i<num;i++){
    printf("%d",array[i]);
    if(i!=num-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
}

void mergesort(int *array,int left, int right){
  int mid;
  if(left<right-1){
    mid=(left+right)/2;
    mergesort(array,left,mid);
    mergesort(array,mid,right);
    merge(array,left,mid,right);
  }
}

void merge(int *array,int left,int mid, int right){
  int i,j,k,num1,num2,array1[250001],array2[250001];
  num1=mid-left;
  num2=right-mid;
  for(i=0;i<num1;i++) array1[i]=array[left+i]; /*left array*/
  for(i=0;i<num2;i++) array2[i]=array[mid+i]; /*right array*/
  array1[num1]=HUGE; /*insert huge value in array as a keeper*/
  array2[num2]=HUGE;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(array1[i]<=array2[j]){
      array[k]=array1[i];
      i++;
    }
    else{
      array[k]=array2[j];
      j++;
    }
  }
}

