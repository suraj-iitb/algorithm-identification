#include<stdio.h>
int search(int *,int,int);
int main(){
  int i,j,n,q,num=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    num += search(S,T[i],n);
  }
  printf("%d\n",num);
  return 0;
}

int search(int *S,int key,int n){
  int left=0,right=n,mid;
  while(left<right){
    mid = (left + right)/2;
      if(S[mid] == key){
	return 1;
      }
      else if(key < S[mid]) right = mid;
      else left = mid +1;
  }
  return 0;
}
