#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#include <bits/stdc++.h>
using namespace std;

const ll MAX=500000;
const ll INFTY=1000000010;

ll L[MAX/2+2],R[MAX/2+2];
int cnt;

void merge(int A[], int left, int mid ,int right){
  int n1=mid - left;
  int n2=right-mid;

  rep(i,n1) L[i]=A[left+i];
  rep(i,n2) R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  int i=0,j=0;
  for(int k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]) A[k]=L[i++];
    else A[k]=R[j++];
  }
}

void mergeSort(int A[],int left,int right){
  if(left+1<right){
    int mid=(left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main() {
  cnt=0;
  int n;
  cin>>n;
  int S[MAX];
  rep(i,n) cin>>S[i];
  
  mergeSort(S,0,n);
  rep(i,n){
    if(i)cout<<" ";
    cout<<S[i];
  }
  cout<<endl;
  cout<<cnt<<endl; 
 
  return 0;
}
