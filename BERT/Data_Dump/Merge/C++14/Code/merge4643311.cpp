#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL cmp = 0;

void merge(UL* A,UL l,UL m,UL r){
 UL n1=m-l, n2=r-m;
 vector<UL> L(n1+1);
 vector<UL> R(n2+1);
 rep(i,n1) L[i]=A[l+i]; L[n1]=~0u;
 rep(i,n2) R[i]=A[m+i]; R[n2]=~0u;
 UL i,j; i=j=0;
 for(UL k=l; k<r; k++){
  cmp++;
  if(L[i]<=R[j]){ A[k]=L[i]; i++; }
  else{ A[k]=R[j]; j++; }
 }
}
void mergeSort(UL* A,UL l,UL r){
 if(l+1<r){
  UL m=(l+r)>>1;
  mergeSort(A,l,m);
  mergeSort(A,m,r);
  merge(A,l,m,r);
 }
}

int main() {
 UL N; scanf("%u",&N);
 UL A[500000]; rep(i,N) scanf("%u",&A[i]);
 mergeSort(A,0,N);
 rep(i,N){ if(i)printf(" "); printf("%u",A[i]); }
 printf("\n");
 printf("%u\n", cmp);
 return 0;
}

