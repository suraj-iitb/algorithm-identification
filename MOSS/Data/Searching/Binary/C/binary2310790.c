#include<stdio.h>

int binarySearch(int n, int key, int *S){

  int left=0,right=n,mid;

  while(left<right){
    mid=(left + right)/2;
    if(S[mid]==key){
      return mid;
    }
    else if(key<S[mid]){
      right=mid;
    }
    else{
      left=mid+1;
    }
}
    return 0;
}

    
int main(){

  int i,n,q,key,count=0;
  int S[100001];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(n,key,S)){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}
 
