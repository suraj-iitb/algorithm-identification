#include<stdio.h>

int binarySearch(int );

int S[100000],n;


int main(){

  int i,j,q,T[50000],C;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&T[i]);
      if((binarySearch(T[i]))==0)
      C++;
    }
    printf("%d\n",C);
    return 0;
}

int binarySearch(int key){

  int left=0,right,mid;
  right=n;
  while(left<right){
    mid=(left+right)/2;
      if(S[mid]==key)
	return 0;
      else if (key<S[mid])
	right=mid;
      else left=mid+1;
  }
  return 1;
}
    
    
