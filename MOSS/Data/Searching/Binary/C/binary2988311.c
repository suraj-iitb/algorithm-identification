#include <stdio.h>
#define s 1000000000
#define q 50000 

int binarySearch(int);

int num,A[s];

int main(){


  int i,num2,a,count=0;       

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
    
  scanf("%d",&num2);
  for(i=0;i<num2;i++){
    scanf("%d",&a);
    count+=binarySearch(a);
  }
  printf("%d\n",count);
  return 0;
}
    
int  binarySearch(int key)
{
  int mid,left,right;
  left=0;
  right= num;
  while(left<right){
    mid = (left + right)/2;
    if(A[mid]==key){
      return 1;
    }
    else if(key<A[mid]){
      right=mid;
    }
    else left = mid + 1;
  }
  return 0;
    }

