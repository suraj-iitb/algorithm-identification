#include<stdio.h> 

#define NMAX 100000
#define QMAX 50000

int main(){
  int i,j,k,n,q,count=0,S[NMAX],T[QMAX],left=0,right,mid;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }

  right=i;
  
  for(k=0;k<q;k++){
    while(left<right){
      mid=(left+right)/2;
      if(S[mid]==T[k]){
	count++;
	//printf("hoge\n");
	break;	
      }
      else if(T[k]<S[mid]){
	right=mid;
      }
      else if(T[k]>S[mid]){
	left=mid+1;
      }
    }
    right=n;
    left=0;
  }
  printf("%d\n",count);
  return 0;
}
    
    
      
      
      
  

