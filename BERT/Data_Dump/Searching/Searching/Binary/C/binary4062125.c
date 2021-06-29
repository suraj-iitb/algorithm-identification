#include<stdio.h>

int binarySearch(int,int *,int);

int main(){
  int a,S[100000],b,T[50000],i,j,k=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&b);
  for(j=0;j<b;j++){
    scanf("%d",&T[j]);
    if(binarySearch(a,S,T[j])==1)
      k++;
    else if(binarySearch(a,S,T[j])==0)
      continue;
  }
  printf("%d\n",k);
  return 0;
}
int binarySearch(int n,int *A,int key){
  int left,right,mid;
  left = 0;
  right = n;
  while(left<right){
    mid = (left+right)/2;
    if(A[mid]==key)
      return 1;
    else if(key<A[mid])
      right = mid;
    else
      left = mid+1;
  }
  return 0;
}
      
	      

