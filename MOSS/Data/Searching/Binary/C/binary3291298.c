#include <stdio.h>
#define NOT_FOUND -1
int main(){
  int a,n,key,i,n2,count = 0;
  int A[100000];
  int brinarysearch(int,int *,int);
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&n2);
  for(i=0;i<n2;i++){scanf("%d",&key);
   a = brinarysearch(n,A,key);
   if(a!=NOT_FOUND)count++;

  }printf("%d\n",count);
  return 0;
}

int brinarysearch(int n,int A[],int key){
  int left = 0;
  int right = n,mid;
  while(left<right){
    mid = (left + right) / 2;
	  if(A[mid] == key)
            return mid;
	  else if(key<A[mid])
            right = mid;
        else
	  left = mid + 1;
  }
  return NOT_FOUND;
  
}

