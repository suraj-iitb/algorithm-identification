#include<stdio.h>
int search(int,int);
int S[100000];
int main(){
  int cn=0,i,n,q,g;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&g);
    if(search(g,n)==1)cn++;
  }
  printf("%d\n",cn);
  return 0;
}
  

int search(int key,int n){
  int left=0;
  int right=n;
  int m=n/2;
  while(left<right){
    m=(left+right)/2;
    if(S[m]==key)return 1;
    else if(key<S[m])right=m;
    else left=m+1;
  }
  return 0;
}
        
  

