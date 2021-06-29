#include<stdio.h>
#define N 100000
#define Q 50000

int binarySearch();

int S[N],n,key;

int main(){
  int T[Q],q,i,c=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    key=T[i];
    if(binarySearch()) c++;
  }

  printf("%d\n",c);

  return 0;
  
}

int binarySearch(){
  int left,right,mid;

  left=0;
  right=n;

  while(left<right){

    mid = (left + right)/2;

    if(S[mid]==key) return 1;

    else if(key < S[mid]) right = mid;

    else left = mid + 1;
  }

  return 0;
}
