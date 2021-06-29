#include <stdio.h>
#define v 500000
#define V 2000000000

int M[v/2+2], S[v/2+2];
int c;
void merge(int T[], int n, int l, int m, int r)
{
  int i,j,k,n1,n2;
  n1 = m-l;
  n2 = r-m;
  for(i=0; i<n1; i++)
    M[i] = T[l+i];
  for(i=0; i<n2; i++)
    S[i] = T[m+i];
  M[n1] = S[n2] = V;
  i = 0;
  j = 0;
  for(k=l; k<r; k++){
    c++;
    if(M[i]<=S[j]) T[k] = M[i++];
    else T[k] = S[j++];
  }
}
void mergeSort(int T[], int n, int l, int r)
{
  int m;
  if(l+1<r){
    m = (l+r)/2;
    mergeSort(T, n, l, m);
    mergeSort(T, n, m, r);
    merge(T, n, l, m, r);
  }
}
int main()
{
  int n,i,T[v];
  scanf("%d",&n);
  c = 0;
  for(i=0; i<n; i++){
    scanf("%d",&T[i]);
  }
  mergeSort(T, n, 0, n);
  for(i=0; i<n-1; i++){
    printf("%d ",T[i]);
  }
  printf("%d\n",T[n-1]);
  printf("%d\n",c);

  return 0;
}

