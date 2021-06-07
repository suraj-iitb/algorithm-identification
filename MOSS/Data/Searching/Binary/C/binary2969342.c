#include<stdio.h>

#define N 100000
#define Q 50000

int main(){
  int i,n,q,c=0;
  int S[N],T[Q];
  int key,left,right,mid;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<q;i++){
    key = T[i];
    left = 0;
    right = n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid] == key){
	c++;
	break;
      }else if(key < S[mid]){
	right = mid;
      }else{
	left = mid+1;
      }
    }
  }

  printf("%d\n",c);
  
  return 0;
}

