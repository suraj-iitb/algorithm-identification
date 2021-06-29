//Merge sort マージソート
#include<stdio.h>

int S[500000], count = 0;

void MergeS(int, int, int);
void Mer(int, int, int, int);

int main(){
  int n, i;

  scanf("%d",&n);
  for(i=0 ; i<n ; i++)scanf("%d",&S[i]);

  MergeS(n, 0, n);

  for(i=0 ; i<n ; i++){
    if(i != 0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

void MergeS(int n, int l, int r){
  int m, i;
  if(l+1<r){
    m = (l+r)/2;
    MergeS(n, l, m);
    MergeS(n, m, r);
    Mer(n, l, m, r);
    }
}

void Mer(int n, int l, int m, int r){
  int n1, n2, L[500000], R[500000], k, i, j;

  n1 = m-l;
  n2 = r-m;

  for(i=0 ; i<n1 ; i++)L[i] = S[l+i];

  for(i=0 ; i<n2 ; i++)R[i] = S[m+i];

  L[n1] = 1000000000;
  R[n2] = 1000000000;

  i = 0;
  j = 0;

  for(k=l ; k<=r-1 ; k++){
    count++;
    
    if(L[i]<=R[j]){
      S[k] = L[i];
      i = i+1;
    }
    else{
      S[k] = R[j];
      j = j+1;
    }
  }
}

