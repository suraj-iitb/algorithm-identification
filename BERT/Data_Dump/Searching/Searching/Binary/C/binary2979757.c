#include <stdio.h>


int main(){

  int n,q,S[100000],T[100000],i,j,count=0,left,right,mid,key;

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&S[i]);

  }
   scanf("%d",&q);

  for(i=0;i<q;i++){

    scanf("%d",&T[i]);

  }
  for(j=0;j<q;j++){
    
    key=T[j];
    S[n]=key;
      left=0;
      right=n;
      while(left<right){

      mid=(left+right)/2;
      // printf("%d\n",mid);
      if(S[mid]==key){
	count++;
	break;
      }
      else if(key<S[mid]){
	
	right=mid;

      }
      else  left=mid+1;
      
      }
  }
  

  printf("%d\n",count);

  return 0;
}

  
  

