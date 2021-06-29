#include<stdio.h>
int n;
int binarySearch(int *,int );
int main(){
   int i,S[1000000],q,key,count=0,T[1000000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    count+=binarySearch(S,T[i]);
  }
  printf("%d\n",count);
  
  return 0;

}


int binarySearch(int *A,int key){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid] == key){
      return 1;
    }else if(key<A[mid]){//keyがmidよりも小さい
      right=mid;
    }else{//keyがmidよりも大きい
      left=mid+1;
    }
  }
  return 0;
}
