#include<stdio.h>
#define N 100000

int binarySearch(int[],int,int);



int main(){
  int i,n,q,k,sum=0;
  int A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(binarySearch(A,n,k)!=0) sum++;
  }
  printf("%d\n",sum);


  return 0;



}


int binarySearch(int A[],int x,int y){
  int left = 0;
  int right = x;
  int mid;

  while(left<right){
    mid=(left+right)/2;

    if(A[mid]==y){
      return 1;
    }

    if(y<A[mid]){
      right=mid;
    }

    else if(y>A[mid]){
      left=mid+1;
    }
  }
    return 0;
}
