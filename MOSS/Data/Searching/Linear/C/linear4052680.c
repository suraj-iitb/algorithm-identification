#include <stdio.h>

int search(int,int,int[]);

int main(){
  int n,q,i,key,ans=0;
  int S[10000];

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
  int i;
  
  for(i=0;i<n;i++){
    if(S[i] == key)return 1;
  }
  
  return 0;
}

