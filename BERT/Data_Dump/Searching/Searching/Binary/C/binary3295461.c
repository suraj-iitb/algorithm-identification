#include<stdio.h>

int n,S[100000];
int search(int T){
  int left=0;
  int right=n;
  int mid;
  while(left < right){
    mid=(left + right)/2;
    if(T == S[mid])
      return 1;
    if(T > S[mid])
      left=mid+1;
    else if(T < S[mid])
      right=mid;
  }
  return 0;
}

int main(){
  int q,T,i,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
    if(search(T)){
      count++;
    }
  }
  printf("%d\n",count);
  return 0;
}


      

