#include <stdio.h>

int Bsearch(int *,int *,int,int);

int main(){
  int S[100000],T[50000],n,q,i,j;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
  }

  printf("%d\n",Bsearch(S,T,n,q));
  return 0;

}

int Bsearch(int *A, int *B, int n, int q){
  int cnt = 0,i,mid,left,right;
  
  for(i = 0; i < q; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right)/2;
      if(A[mid] == B[i]){
	cnt++;
	break;
      }else if(B[i] < A[mid]){
	right = mid;
      }else{
	left = mid + 1;
      }
    }
  }
  
  return cnt;
}

