#include <stdio.h>

int A[1000000],n;

int binarysearch(int key){
  int left=0;
  int right=n;
  int mid;

  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key){
    return 1;
    }
    else if(key<A[mid]){
      right=mid;
    }
    else{
      left=mid+1;
    }
  }
    return 0;
}

  int main(){
    int q,key,i;
    int count=0;

    scanf("%d",&n);
    for(i=0;i<n;i++){
      scanf("%d",&A[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&key);
      count=count+binarysearch(key);
    }
    printf("%d\n",count);

    return 0;
  }

