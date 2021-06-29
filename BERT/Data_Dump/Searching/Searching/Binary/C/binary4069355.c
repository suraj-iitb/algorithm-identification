#include <stdio.h>

int binarySearch(int,int,int *);

int main()
{
  int i,S[100000],T[50000],Sn,Tn,key,cnt=0;
  scanf("%d",&Sn);
  for(i=0;i<Sn;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&Tn);
  for(i=0;i<Tn;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<Tn;i++){
    key = T[i];
    if(binarySearch(Sn,key,S)==1) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}

int binarySearch(int n,int key,int *A){
  int right,left,mid;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right)/2;
    if(key == A[mid]) return 1;
    else if(key < A[mid]) right = mid;
    else left = mid +1;
  }
  return 0;
}

