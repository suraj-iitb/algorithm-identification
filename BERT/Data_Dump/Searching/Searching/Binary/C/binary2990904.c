#include<stdio.h>

int main(){
  int i,n,c,count,left,right,A[1000000],B[1000000],mid;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);

  }

  scanf("%d",&c);
  for(i=0;i<c;i++){
    scanf("%d",&B[i]);

  }

  for(i=0;i<c;i++){
    left=0;
    right=n;

    while(left<right){

      mid=(left+right)/2;
      if(A[mid]==B[i]) {count++; break;}
      else if(B[i]<A[mid]) right=mid;
      else left = mid+1;
    }
  }
  printf("%d\n",count);
}
