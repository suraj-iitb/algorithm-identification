#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  int n,S[N],q,T[Q],i,left,right,count=0,mid;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }


  for(i=0;i<q;i++){ /*key T[]*/
    left=0;
    right=n;
    while(left<right){
      mid = (left + right)/2;
      if(T[i]==S[mid]){
	count++;
	break;
      }else if(T[i]<S[mid]){
	right=mid;
      }else{
	left=mid+1;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}
  

