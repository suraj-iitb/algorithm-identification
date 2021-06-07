#include <stdio.h>

int binarysearch(int);
int array[100000],num1;
int main(){
  int i,num2,key,count=0;
  scanf("%d",&num1);
  for(i=0;i<num1;i++) scanf("%d",&array[i]);

  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&key);
    if(binarysearch(key)==1) count++;
  }
  printf("%d\n",count);
  return 0;
}

int binarysearch(int key){
  int left=0,right=num1,mid;

  while(left<right){
    mid=(left+right)/2;
    if(key==array[mid]) return 1; /* found key */
    if(key>array[mid]) left=mid+1;
    else if(key<array[mid]) right=mid;
  }
  return 0;
}

