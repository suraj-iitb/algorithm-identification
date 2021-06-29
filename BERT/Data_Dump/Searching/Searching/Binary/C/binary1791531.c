#include<stdio.h>
int binarySearch(int);
int N,A[100000];
int main(){
  int i,M,key,l=0,c;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);
  scanf("%d",&M);
  for(i=0;i<M;i++){
    scanf("%d",&key);
    c=binarySearch(key);
    if(c>=0 && c<=100000)
      l++;
  }
  printf("%d\n",l);
  return 0;
}

int binarySearch(int key){
  int left=0;
  int right=N;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==key) return mid;
    else if(key<A[mid])
      right=mid;
    else
      left=mid+1;
  }
  if(A[mid]!=key) return -1;
}
    
