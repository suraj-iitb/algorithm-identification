#include <stdio.h>
int BinarySearch(int );
int S[1000000],n;
int main(){

  int j,i,q,T[1000000],count=0,flag;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
    }
  scanf("%d",&q);
   for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
    for(j=0;j<q;j++){
      flag=BinarySearch(T[j]);
      if(flag==1) count++;
    }
 
  printf("%d\n",count);
  return 0;


}

int BinarySearch(int key){
  int i,left=0,right,mid;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(S[mid]==key)return 1;
    else if(key< S[mid]) right=mid;
    else left=mid+1;
  }
  return 0;
}
