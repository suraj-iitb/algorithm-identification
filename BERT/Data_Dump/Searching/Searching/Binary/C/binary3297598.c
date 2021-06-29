#include<stdio.h>

#define N 100000

int binarySearch(int *,int ,int);

int main(){
  int i,n,j,S[N],q,c,count = 0;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(j = 0;j < q;j++){
    scanf("%d",&c);
    if(binarySearch(S,c,n)) count++;
  }

  printf("%d\n",count);

  return 0;

}

int  binarySearch(int A[],int key,int n){
  int left = 0,mid,right;
  right = n;
  while (left < right){
    mid = (left + right) / 2;
    if (A[mid] == key){
        return 1;
    }
    else if(key < A[mid]){
      right = mid;
    }
    else if(key > A[mid]){
      left = mid + 1;
    }
  }
  return 0;
}

