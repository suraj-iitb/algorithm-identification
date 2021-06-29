#include<stdio.h>
#define MAX 100000
int main(){
  int n,q,i,j,l=0,r,mid,count=0;
  int S[MAX],T[MAX];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    r=n;
    l=0;
    scanf("%d",&T[i]);
    while(l<r){
      mid=(l+r)/2;
      //printf("\nmid = %d key = %d\n",mid,T[i]);
      if(S[mid]==T[i]){
	count+=1;
	break;
      }
      else if(S[mid]<T[i]){
	l=mid+1;
      }
      else{
	r=mid;
      }
      
    }
  }
  printf("%d\n",count);
  return 0;
}

