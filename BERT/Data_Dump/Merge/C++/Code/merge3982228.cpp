#include<bits/stdc++.h>
using namespace std;

const int INFTY=1000000007;
int cnt=0;

void merge(int A[], int left, int mid, int right) {
  int n1=mid-left;
  int n2=right-mid;
  vector<int> L(n1+1), R(n2+1);
  for (int i=0;i<n1;i++) L[i]=A[left+i];
  for (int i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=R[n2]=INFTY;
  for (int i=0, j=0, k=left; k<right; k++) {
    cnt++;
    if (L[i] <= R[j]) A[k]=L[i++];
    else A[k]=R[j++];
  }
}

void mergeSort(int A[], int left, int right) {
  if (left+1<right) {
    int mid=(left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n; cin>>n;
  int a[500002];
  for (int i=0;i<n;i++) cin>>a[i];

  mergeSort(a, 0, n);
  for (int i=0;i<n;i++) {
    if (i) cout<<" ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<cnt<<endl;
  return 0;
}
