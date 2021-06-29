#include<stdio.h>
#define N 100000

int main(){

  int S[N],T[N];
  int n,q,i,count=0,mid=0,left,right;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  

  for(i=0;i<=q-1;i++){

    left=0;
    right=n;

    while(left<right){

      mid=(left+right)/2;

      if(S[mid]==T[i]){
	count++;
	break;
      }else if(T[i]<S[mid]){
	right=mid;
      }else{
	left=mid+1;
      }

    }//while1

  }//for

  printf("%d\n",count);

  return 0;

}

