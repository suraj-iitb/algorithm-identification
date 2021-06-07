#include <stdio.h>

int binarySearch(int);

int data[100000],n;

int main(){
  int i,a,b,c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
      }

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&b);
    if(binarySearch(b)){
      c++;
    }
  }
  printf("%d\n",c);

  return 0;
}

int binarySearch(int key){
  int left=0;
  int right=n;
  int mid;
  
  while(left<right){
    mid=(left+right)/2;
  if(data[mid]==key){
    return mid;
  }
  if(data[mid]>key){
    right=mid;
  }
  if(data[mid]<key){
    left=mid+1;  
}
  }
  return 0;
  }

