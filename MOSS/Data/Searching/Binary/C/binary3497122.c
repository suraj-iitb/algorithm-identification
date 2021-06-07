#include<stdio.h>

#define LENn 100000

int binarySeach(int a[],int n,int key){
  int left = 0;
  int right = n;
  int mid;
  while(left<right){
    mid = (left+right)/2;
    if(a[mid]==key){
      return 1;
    }else if(key<a[mid]){
      right = mid;
    }else{
      left = mid + 1;
    }
  }
  return 0;
}

int main(){
  int a[LENn],n;
  scanf("%d",&n);
  for(int i=0;i<n; i++){
    scanf("%d",&a[i]);
  }
  int q,key;
  int sum=0;
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySeach(a,n,key)) sum++;
  }
  printf("%d\n",sum);
}

