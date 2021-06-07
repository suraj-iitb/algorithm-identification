#include <stdio.h>

int binarySearch(int *,int,int);

int main(){
  int S[100000];
  int T[50000];
  int N,q,i;
  int cnt=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(binarySearch(S,N,T[i]))cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}

int binarySearch(int A[],int N,int key){
  int right=N;
  int left=0;
  int mid=0;

  while(right > left){

    mid = (left + right) / 2;

    if(A[mid] == key)return 1;

    if(A[mid] < key){
      left = mid + 1;
    }
    else if(A[mid] > key){
      right = mid;
    }

  }

  return 0;
}
    

