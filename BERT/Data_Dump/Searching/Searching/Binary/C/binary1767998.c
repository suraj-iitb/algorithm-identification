#include<stdio.h>

int binarySearch(int *,int,int);

int main(){
  int i;
  int key;
  int S_num[1000000];
  int T_num;
  int num_in_1;
  int num_in_2;
  int count=0;

  scanf("%d",&num_in_1);

  for(i=0;i<num_in_1;i++){
    scanf("%d",&S_num[i]);
  }

  scanf("%d",&num_in_2);

  for(i=0;i<num_in_2;i++){
    scanf("%d",&key);
    if(binarySearch(S_num,key,num_in_1)==1){
      count++;
    }
  }
  
  printf("%d\n",count);
  
  return 0;
}

int binarySearch(int S_num[],int key,int n){
  int left=0;
  int right=n;
  int mid;
  
  while(left<right){
    mid=(left+right)/2;
    if(S_num[mid]==key){
      return 1;
    }else if(key<S_num[mid]){
      right=mid;
    }else{
      left=mid+1;
    }
  }
  
  return -1;
}
