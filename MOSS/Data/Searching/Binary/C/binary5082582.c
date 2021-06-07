#include<stdio.h>

#define N 100000
#define Q 50000
#define NIL 0

int BinarySearch(int,int *,int);

int main(){
  int S[N],T[Q];
  int i,j,count=0;
  int n;
  int q;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);

  for(i=0;i<q;i++) count+=BinarySearch(n,S,T[i]);

  printf("%d\n",count);

  return 0;
}

int BinarySearch(int n,int A[],int key){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
      mid = (left + right)/2;
    if(key == A[mid]) return 1;
    if(key > A[mid]) left = mid + 1;
    else if(key < A[mid]) right = mid;
         }
  return NIL;
}


