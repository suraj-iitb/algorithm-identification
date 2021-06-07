#include <stdio.h>

int search(int,int,int[]);

int main(){
  int n,q,i,key,ans=0;
  int S[100000];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);

    ans += search(key,n,S);
  
  }
  printf("%d\n",ans);
  

  return 0;
}

int search(int key,int n,int S[]){
  int i,left,right,middle;
  
  left = 0;
  right = n;

  while(left < right){
    middle = (left + right)/2;
    if(S[middle] == key) return 1;
    else if(key < S[middle])right = middle;
    else left = 1 + middle;
  }
  return 0;
}

