#include <iostream>
#include <vector>
using namespace std;

void trace(vector<int> a,int n){
  for(int i=0;i<n;++i){
    if(i!=n-1) cout << a[i] <<" ";
    else cout << a[i];
  }
  cout << endl;
}

void InsertionSort(vector<int>a,int n){
  for(int i=1;i<n;++i){
    int v=a[i],j;
    for(j=i-1;j>=0&&a[j]>v;--j) a[j+1]=a[j];
    a[j+1]=v;
    trace(a,n);
  }
}

int main() {
    int N; cin >> N; vector<int> A(N);
    for(int i=0;i<N;++i) cin >> A[i];
    trace(A, N);
    InsertionSort(A, N);
    return 0;
}
