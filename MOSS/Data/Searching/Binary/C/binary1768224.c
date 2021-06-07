#include<stdio.h>

#define MAX 100000

int binarySearch(int);

int arr1[MAX];
int n1;

int main(){
  
  int i,n2,ans=0,key;

  
  scanf("%d",&n1);
  for(i=0;i<n1;i++){
    scanf("%d",&arr1[i]);
  }
  
  scanf("%d",&n2);
  for(i=0;i<n2;i++){
    scanf("%d",&key);
    if(binarySearch(key)==1){
      ans++;
    }
  }
  
  printf("%d\n",ans);


  return 0;
}
 

int binarySearch(int key){

  int left,right,mid;
  
  left = 0;
  right = n1;
  
  while(left<right){
    mid=(left + right)/2;
    if(arr1[mid]==key){
      return 1;
    }
    else if(key<arr1[mid]){
      right = mid;
    }
    else left = mid +1;
  }
  
  return 0;
  
}
