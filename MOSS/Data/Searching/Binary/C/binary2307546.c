#include <stdio.h>

int main(){
  int n,q,i,left,right,mid,counter=0;
  int s[100000],t[50000];
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(s[mid]==t[i]){
	counter++;
	break;
      }
      else if(s[mid]>t[i])right=mid;
      else if(s[mid]<t[i])left=mid+1;
    }
  }
  printf("%d\n",counter);  
  return 0;
}
