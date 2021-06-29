#include<stdio.h>
#define nMax 100000
#define qMax 50000

int binarySearch(int key,int S[],int n){
  int left,right,mid;
  left=0;
  right=n;
  while(left<right){
    mid = (left+right)/2;
    if(S[mid] == key){
      return mid;
    }
    else if(key<S[mid]){
      right = mid;
    }
    else left = mid+1;
    
  }
  return 0;
}
  
int main(){

  int n,i,j,q,z,count=0;
  int S[nMax],T[qMax];

  scanf("%d",&n);

  if(n <= nMax){
    for(i=0;i<n;i++){
      scanf("%d",&S[i]);
    }
  }
  else printf("Not found\n");
  
    scanf("%d",&q);

    if(q <= qMax){
      for(j=0;j<q;j++){
	scanf("%d",&T[j]);
	if(binarySearch(T[j],S,n))
	  count++;	  
      }
    }
    else printf("Not found\n");

   

    printf("%d\n",count);

    return 0;
}

