#include<stdio.h>
int BinarySearch(int [],int,int);

int main(){
  int i, n, q, key, number=0, S[100000];

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&key);
    if(BinarySearch(S,n,key) != 0) number++;
  }

  printf("%d\n",number);

  return 0;
}

int BinarySearch(int A[], int x, int y){
  int left=0, right=x, mid;

  while(left < right){
    mid = (left + right) / 2;
    if(A[mid] == y) return 1;
    if(A[mid] > y) right = mid;
    else if(A[mid] < y) left = mid + 1;
  }

  return 0;
}

    

