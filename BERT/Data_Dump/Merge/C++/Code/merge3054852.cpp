#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int c;
void marge(vector<int>& A, int l, int m, int r)
{
  int i,j,k,n1=m-l,n2=r-m;
  vector<int> L(n1+1),R(n2+1);
  
  for(i=0; i<n1; i++) L[i]=A[l+i];
  for(i=0; i<n2; i++) R[i]=A[m+i];
  L[n1]=INT_MAX; R[n2]=INT_MAX;
  i=0; j=0;
  for(k=l; k<r; k++){
    c++;
    if(L[i]<=R[j]){ A[k]=L[i]; i++; }
    else{ A[k]=R[j]; j++; }
  }
}
void margeSort(vector<int>& A, int l, int r)
{
  if(l+1<r){
    int m=(l+r)/2;
    margeSort(A, l, m);
    margeSort(A, m, r);
    marge(A, l, m, r);
  }
}
int main()
{
  c=0;
  int i,j,n;
  vector<int> S;
  cin>>n; S.resize(n);
  for(i=0; i<n; i++) cin>>S[i];
  margeSort(S,0,n);
  for(i=0; i<n-1; i++) cout<<S[i]<<' '; cout<<S[n-1]<<endl;
  cout<<c<<endl;
  return 0;
}
