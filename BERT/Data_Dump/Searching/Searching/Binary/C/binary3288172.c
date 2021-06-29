#include<stdio.h>
#define N 100000
int check(int *,int,int);
int main(){
  int i,j,cnt=0,S[N],T,n,q;
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T);
cnt+=check(S,T,n);
  }

  printf("%d\n",cnt);
  return 0;
}
int check(int S[],int t,int n){
  int l,m,r;
  l=0;
  r=n;
  while(l<r){
  
    m=l+r;
    m/=2;


    if(S[m]==t){
      
      return 1;
    }
    else if(S[m]<t)
      l=m+1;
    else if(S[m]>t)
      r=m;

    
  }
  return 0;

}

