#include <stdio.h>

int linearsearch(int key,int S[],int n){
  int i;
  for(i=0;i<n;i++){
    if(key == S[i]) return 1;
  }
  return 0;
}

int main(){
  int i,n,S[10000],q,T[500],ans=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  
  for(i=0;i<q;i++){
    if(linearsearch(T[i],S,n) == 1)
      ans++;
  }
  printf("%d\n",ans);
  return 0;
}
