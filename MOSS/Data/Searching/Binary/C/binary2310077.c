#include<stdio.h>
#define Found 1
#define NotFound -1
int binarysearch(int *A,int keyword,int num1);
int main(){
  int num1,num2,i,number[1000000],keyword,count=0;
  scanf("%d",&num1);
  for(i=0;i<num1;i++){
    scanf("%d",&number[i]);
  }
  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&keyword);
    if(binarysearch(number,keyword,num1)==Found)count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarysearch(int *A,int keyword,int num1){
  int left=0,right,mid;
  right=num1;
  while(left<right){
    mid=(left+right)/2;
    if(keyword==A[mid])return Found;
    if(keyword>A[mid]) left=mid+1;
    else if(keyword<A[mid])right = mid;
  }
  return NotFound;
}
