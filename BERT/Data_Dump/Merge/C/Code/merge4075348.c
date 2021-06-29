#include <stdio.h>

void ma(int*,int,int,int);
void mS(int*,int,int);
int cnt=0;

int main(){
  int i,n;

  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  
  mS(S,0,n);
  
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n%d\n",S[n-1],cnt);
  
  return 0;
}

void ma(int *S, int l,int m,int r){
  int i,j,k,n1=m-l,n2=r-m;
  int L[n1],R[n2];

  for(i=0;i<n1;i++){
    L[i]=S[l+i];
  }
  for(i=0;i<n2;i++){
    R[i]=S[m+i];
  }
  L[n1]=1000000000;
  R[n2]=1000000000;
  i=0;
  j=0;
  for(k=l;k<r;k++){
    if(L[i]<=R[j]){
      S[k]=L[i];
      i+=1;
    }
    else{
      S[k]=R[j];
      j+=1;
    }
    cnt++;
  }
}

void mS(int *S,int l, int r){
  int m;
  
  if(l+1<r){
    m=(l+r)/2;
    mS(S,l,m);
    mS(S,m,r);
    ma(S,l,m,r);
  }
  
}
