#include <stdio.h>

#define INFTY 2000000000
#define A 500000

void m1(int[],int,int,int,int);
void m2(int[],int,int,int);

int L[A/2+2],R[A/2+2];
int q;

int main(){
  int n,S[500000],i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  m2(S,n,0,n);

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",q);

  return 0;
}

void m1(int S[],int n,int l,int m,int r){
  int n1,n2,i,j,k;
  
  n1 = m-l;
  n2 = r-m;

  for(i=0;i<n1;i++){
    L[i]=S[l+i];
  }

  for(i=0;i<n2;i++){
    R[i]=S[m+i];
  }

  L[n1]=INFTY;
  R[n2]=INFTY;

  i=0;
  j=0;

  for(k=l;k<r;k++){
    q++;
    if(L[i] <= R[j]){
      S[k]=L[i];
      i=i+1;
    }else{
      S[k]=R[j];
      j=j+1;
    }
  }
}

void m2(int S[],int n,int l,int r){
  int m;
  
  if(l+1 < r){
    m = (l+r)/2;
    m2(S,n,l,m);
    m2(S,n,m,r);
    m1(S,n,l,m,r);
  }
}
    
    
  

