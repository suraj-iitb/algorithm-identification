#include<stdio.h>
#define MAX 100000
int A[MAX];

int BinarySearch(int key,int n){
  int left = 0;
  int right = n;
  int mid;
  
  while (left < right)
    {
      mid = (left + right) / 2;
      if (A[mid] == key)return 1; //FOUND
      else if (key < A[mid])right = mid;
      else left = mid + 1;
    }
  return 0;//NOT_FOUND
}

int main(){
  int i;
  int n;
  int key_n;
  int key;
  int count=0;
  
  scanf("%d",&n);//INPUT
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  scanf("%d",&key_n);
  for(i=0;i<key_n;i++){
    scanf("%d",&key);
    if(BinarySearch(key,n)==1)count++;
  }
  
  printf("%d\n",count);
  return 0;
}
/*
  Aの数
  Aの要素
  確かめるkeyの要素
  keyの要素

  一致した数
*/

