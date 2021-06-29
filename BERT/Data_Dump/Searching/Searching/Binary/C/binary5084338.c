#include <stdio.h>
int S[100000],T[50000];
int binarySearch(int n,int key){
  int left,right,mid;
  
  left = 0;
  right = n;
  while (left < right){
    
    mid = (left + right) / 2;
    if (S[mid] == key)
      return mid;
    else if (key < S[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return -1;
  
}
int main(){
  int i,n,q,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&T[i]);
	if(binarySearch(n,T[i])>=0){
	  count++;
	}
    }
   
    printf("%d\n",count);
    return 0;
}

