#include<bits/stdc++.h>
#define INF 1e9
#define N 500000
using namespace std;

int cnt=0;

void merge(int A[],int left,int mid,int right)
{
  int n1 = mid - left;
  int n2 = right - mid;

  int L[n1+1],R[n2+1];
  for(int i=0;i < n1;i++){
    L[i] = A[left+i];
  }
  for(int i=0;i < n2;i++){
    R[i] = A[mid+i];
  }
  
  L[n1]=R[n2]=INF;
  int i=0,j=0;
  for(int k=left;k < right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
    cnt++;
  }
}

void mergesort(int A[],int left,int right)
{
  if(left+1 < right){
    int mid = (left + right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main()
{
  int n;
  cin >> n;
  int a[N];
  for(int i=0;i < n;i++){
    cin >> a[i];
  }
  int left=0;
  int right=n;
  
  mergesort(a,left,right);

  for(int i=0;i < n;i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}

