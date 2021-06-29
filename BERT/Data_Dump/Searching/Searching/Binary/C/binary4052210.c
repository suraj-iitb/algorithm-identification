#include <stdio.h>
#include <stdlib.h>



int main(){
  int *S;
  int n;
  int q;
  int *T;
  int i,j;
  int jg=0;
  int left;
  int right;
  int mid;

  scanf("%d",&n);
  S=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  T=(int *)malloc(q*sizeof(int));

  for(i=0;i<q;i++)scanf("%d",&T[i]);
  
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==T[i]){
	jg++;
	break;
      }
      else if(T[i]<S[mid])right=mid;
      else left=mid+1;
    }
  }
  printf("%d\n",jg);
  return 0;
}
    
  
      

     
    
      

