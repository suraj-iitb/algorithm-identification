#include<stdio.h>
int main(){
  int i,n,S[100000],q,T[50000],key,count=0,flag,right,left,mid;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++) scanf("%d",&T[i]);
  
  for(i=0;i<q;i++){
    key = T[i];
    left=0;
    right=n;
    flag=0;
      
      while(left < right){
        mid = (left + right) / 2;
        
        if(S[mid] == key){
          flag=1;
          break;
        }
        else if(key < S[mid]) right = mid;
        else left = mid+1;
      }
    if(flag == 1) count++;
  }

  printf("%d\n",count);
    
  return 0;
}

