#include<stdio.h>
int binarysearch(int);
int A[1000000],n;
int main(){
  int i,j,k,count=0;
    scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&k);
    if(binarysearch(k))count++;
  }
  printf("%d\n",count);
  return 0;
}
int binarysearch(int key){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left+right)/2;
    if(key==A[mid])return 1;
    if(key>A[mid])left=mid+1;
    else if(key<A[mid])right=mid;
      }
  return 0;
}

			 

		      
 

