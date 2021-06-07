#include <stdio.h>
#define n 100005
#define q 50005

int main(){
  int i,j,count=0,S[n],T[q],Ain,Bin,left,right,mid;

  scanf("%d",&Ain);  
  for(i=0;i<Ain;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&Bin);
  for(i=0;i<Bin;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<Bin;i++){
    left=0;
    right=Ain;
    j=T[i];
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==j){
	count++;
	break;
      }
      else if(j>S[mid])
	left=mid+1;
      
      else if(j<S[mid])
	right=mid;
    }
  }
  printf("%d\n",count);
  return 0;
}
