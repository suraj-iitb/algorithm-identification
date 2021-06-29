#include<stdio.h>
#define MAX 100000
int Search();
int main(){
    int A[MAX],i,n,q,count=0,key;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(Search(A,key,n)==1) count++;
  }
  printf("%d\n",count);
  return 0;
}
int Search(int A[],int key,int n){
  int left=0,right,mid;
  right = n;
  while(left <  right){
    mid = (left + right) / 2;
    if (A[mid] == key)
	      return 1;
	else if(key <A[mid])
	  right = mid;
	else
	  left= mid +1;
  }
     return 0;
}

