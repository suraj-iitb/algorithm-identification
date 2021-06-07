#include <stdio.h>

int BinarySearch(int,int *,int);

int main()
{
  int S[100000],T[50000],S_num,T_num,cnt = 0,key;
  scanf("%d",&S_num);
  for(int i = 0; i < S_num;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&T_num);
  for(int i = 0; i < T_num; i++){
    scanf("%d",&T[i]);
  }
  for(int i = 0;i < T_num;i++){
    key = T[i];
    if(BinarySearch(S_num,S,key) == 1) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}

int BinarySearch(int n,int *A,int key){
  int right,left,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right)/2;
    if(key == A[mid]) return 1;
    if(key > A[mid]) left = mid + 1;
    else if(A[mid] > key) right = mid;
  }
  return 0;
}

