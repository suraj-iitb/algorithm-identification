#include<stdio.h>
int b_search(int);
int n;
int l[100000];
int main(){
  int i;
  int q;
  int q_n;
  int result=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&l[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&q_n);
    result+=b_search(q_n);
  }
  printf("%d\n",result);
  return 0;
}
int b_search(int x){
  int i;
  int mid;
  int left=0;
  int right=n;
  while(left<right){
    mid=(left+right)/2;
    if(l[mid]==x){
      return 1;
    }
    else if(x<l[mid])right=mid;
    else left=mid+1;
  }
  return 0;
}

