#include <stdio.h>
#define N 1000000001
int L[500000],R[500000];
int count;
void X (int hi[],int n,int l,int m,int r);
void Y (int hi[],int n,int l,int r);
int main()
{
  int i,j,k;
  int hi[500000];
  scanf ("%d",&k);
  for (i=0;i<k;i++){
    scanf ("%d",&hi[i]);
  }
  Y(hi,k,0,k);
  for (i=0;i<k;i++){
    printf ("%d",hi[i]);
    if (i!=k-1)
      printf (" ");
  }
  printf ("\n");
  printf ("%d\n",count);
  return 0;
}
void X (int hi[],int n,int l,int m,int r){
  int s,t;
  int i=0,j=0,p;
  s=m-l;
  t=r-m;
  for(i=0;i<s;i++)
    L[i]=hi[l+i];
  for(i=0;i<t;i++)
    R[i]=hi[m+i];
  
  L[s]=N;
  R[t]=N;

  i=0, j=0;
  for (p=l;p<r;p++){
    count++;
    if (L[i]<=R[j]){
      hi[p]=L[i++];
    }else{
      hi[p]=R[j++];
    }
  }
}
void Y (int hi[],int n,int l,int r){
  int m;
  if (l+1<r){
    m=(l+r)/2;
    Y(hi,n,l,m);
    Y(hi,n,m,r);
    X(hi,n,l,m,r);
  }
}

