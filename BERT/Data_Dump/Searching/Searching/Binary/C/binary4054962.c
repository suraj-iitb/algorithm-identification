#include<stdio.h>
int main(){
  int cnt=0,n,q,S[100000],T[50000],i,j=0,le=0,ri,mi;
  scanf("%d",&n);
  for(i=0;i<=n-1;i++)scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<=q-1;i++){
    scanf("%d",&T[i]);
  
  ri=n;
   le=0;
  while(le<ri){
    mi=(le+ri)/2;
    if(T[i]==S[mi]){
      cnt++;
      break;

    }
    else if(T[i]>S[mi]){
      le=mi+1;
      
    }
    else if(T[i]<S[mi]){
      ri=mi;
      
    }
   
  }
  }
  
  
  printf("%d\n",cnt);
  return 0;
}

