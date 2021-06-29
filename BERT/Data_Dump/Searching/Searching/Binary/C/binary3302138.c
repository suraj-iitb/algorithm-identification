#include <stdio.h>
int n;
int A[100000];

binarysearch(int k){
int left=0;
int right=n;
int mid;
while(left<right){
  mid=(left+right)/2;
  if(A[mid]<k){
    left=mid+1;
  }
  if(A[mid]>k){
    right=mid;
  }
  if(A[mid]==k){
    return 1;
  }
 }
return 0;
}
    

int main(){
  int i,q,k,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(binarysearch(k)==1){
      count++;
    }
  }
  printf("%d\n",count);

  return 0;
}

