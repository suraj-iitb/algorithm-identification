#include<stdio.h>
#include<stdlib.h>
#define S 2000000000
 
int comp = 0;
 
int Merge(int ar[], int l, int m, int r){
 
  int n1 = m - l,n2 = r - m;
  int i,j,k;
  int L[n1+1],R[n2+1];
 
  for(i=0;i<=n1-1;i++)
    L[i]=ar[l+i];
  for(i=0;i<=n2-1;i++)
    R[i]=ar[m+i];
  L[n1]=S;
  R[n2]=S;
  i = j = 0; 
  for(k=l; k<=r-1; k++){
    if(L[i]<=R[j]){
      ar[k]=L[i];
      i=i+1;
      comp++;
    }
    else {
      ar[k]=R[j];
      j=j+1;
      comp++;
    }
  }
}
 
int MergeS(int ar[], int l, int r){
 
  int m;
 
  if(l+1<r){
    m=(l+r)/2;
    MergeS(ar, l, m);
    MergeS(ar,m, r);
    Merge(ar, l, m, r);
  }
 
}

int main(){
 
  int n,i,a[500000];
 
  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &a[i]);
 
  MergeS(a, 0, n);
 
  for(i = 0; i < n - 1; i++)
    printf("%d ", a[i]);
  printf("%d\n",a[n - 1]);
  printf("%d\n", comp);
 
  return 0;
   
}
