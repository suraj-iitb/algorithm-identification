#include<stdio.h>
int LinerSearch(int*,int,int);
int main(){
  int n,q,i,key,ans=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(LinerSearch(S,n,key)==1)ans++;
  }
  printf("%d\n",ans);
  return 0;
}

int LinerSearch(int *S,int n,int key){
  int i=0;
  S[n]=key;
  while(S[i]!=key){
    i++;
    if(i==n)return 0;
  }
  return 1;
}
    


      

