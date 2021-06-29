#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
using Card = pair<UL,char>;
Card A[100000];
Card B[100000];

UL partition(Card* pA,UL p,UL r){
 UL x = pA[r].first;
 UL i = p-1;
 for(UL j=p; j<r; j++)
  if(pA[j].first <= x){ i++; swap(pA[i],pA[j]); }
 swap(pA[i+1],pA[r]);
 return i+1;
}

void quicksort(Card* pA,UL p,UL r){
 if(p<r){
  UL q=partition(pA,p,r);
  quicksort(pA,p,q-1);
  quicksort(pA,q+1,r);
 }
}

void margesort(Card* pA,UL p,UL r){
 if(r-p<=1) return;
 UL m=(p+r)>>1;
 margesort(pA,p,m);
 margesort(pA,m,r);
 vector<Card> L(m-p+1); rep(i,m-p) L[i]=pA[p+i]; L[m-p]={~0u,' '};
 vector<Card> R(r-m+1); rep(i,r-m) R[i]=pA[m+i]; R[r-m]={~0u,' '};
 UL i=0, j=0;
 rep(k,r-p){
  if(L[i].first<=R[j].first) {pA[p+k]=L[i];i++;}
  else {pA[p+k]=R[j];j++;}
 }
}

int main() {
 scanf("%u",&N);
 rep(i,N) scanf(" %c%u",&A[i].second,&A[i].first);
 rep(i,N) B[i]=A[i];
 quicksort(A,0,N-1);
 margesort(B,0,N);
 bool stable=true;
 rep(i,N) if(A[i]!=B[i]) stable=false;
 printf(stable?"Stable\n":"Not stable\n");
 rep(i,N) printf("%c %d\n",A[i].second,A[i].first);
 return 0;
}

