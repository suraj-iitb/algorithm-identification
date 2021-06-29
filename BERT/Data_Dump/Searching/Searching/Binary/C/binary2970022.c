#include<stdio.h>

int main(){
  int n,q,i,key,j,k=0,left,right,mid;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(j=0;j<q;j++){
    left = 0;
    right = n;
    key=T[j];
    while(left<right){
      mid = (left + right)/2;
      if(S[mid]==key){
	k++;
	break;
      }
      else if(key<S[mid]){
	right = mid;
      }
      else{
	left = mid + 1;
      }
    }
  }

  printf("%d\n",k);

  return 0;
}
      
      

