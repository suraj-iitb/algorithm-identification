#include <stdio.h>

int s[1000000],sum1;

int search(int t){
  int left=0,right=sum1,mid=0;
  while(left < right){
    mid = (left+right)/2;
    if(t==s[mid]) return 1;
    if(t>s[mid]) left = mid +1;
    else if(t<s[mid]) right = mid;
  }
  return 0;
}
int main(){
  int i,j,sum2,sum3=0,t;
  scanf("%d",&sum1);
  for(i=0;i<sum1;i++) scanf("%d",&s[i]);
  scanf("%d",&sum2);
  for(j=0;j<sum2;j++){
      scanf("%d",&t);
      if(search(t)!=0) sum3++;
  }
  printf("%d\n",sum3);
  return 0;
}
