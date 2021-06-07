#include<stdio.h>

int main(){
  int sn,tn,count=0,i,j,t;
  int s[100000];
  scanf("%d",&sn);
  for(i=0;i<sn;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&tn);
  for(i=0;i<tn;i++){
    scanf("%d",&t);
    int left=0;
    int right=sn;
    while(left<right){
      int mid;
      mid=(left+right)/2;
      if(s[mid]==t){
	count++;
	break;
      }
      else  if(t<s[mid])right=mid;
      else left=mid+1;
    }
  }
  printf("%d\n",count);
  return 0;
}
