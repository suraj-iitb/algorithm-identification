#include<stdio.h>
int binarySearch();
int n,S[100000],key,mid;

int main(){
  int i,q,T[100000],C=0;

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
    if(binarySearch()==-1){
      continue;
    }
    else{
      C++;
    }
  }

  printf("%d\n",C);
}

  int binarySearch(){
    int left=0;
    int right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==key){
	return mid;
      }
      else if(key<S[mid]){
	right=mid;
      }
      else
	left=mid+1; 
    }
    return -1;
  }

