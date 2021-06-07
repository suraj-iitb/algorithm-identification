#include<stdio.h>

#define S_MAX 100000
#define T_MAX 50000

int binarySearch(int key,int*A,int n){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left+right)/2;
    if(A[mid]==key)
      return 1;
    else if(key < A[mid])
      right=mid;
    else left = mid+1;
  }
  return 777;
}

int main(){
  
  int i,n,q;
  int cnt=0,jude;
  int S[S_MAX],T[T_MAX];
   
  scanf("%d",&n);  
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
 
  scanf("%d",&q); 
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);
  
  for(i=0;i<q;i++){
  jude=binarySearch(T[i],S,n);
  if(jude==1)
    cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}
