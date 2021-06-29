#include <iostream>
#include <vector>
using namespace std;

int BubbleSort(vector<int>a, int n){
    int sw=0; bool flg=true;
    for(int i=0;flg;++i){
      flg=false;
      for(int j=n-1;j>i;--j){
        if(a[j-1]>a[j]){
          swap(a[j-1], a[j]);
          flg=true; ++sw;
        }
      }
    }
    for(int i=0;i<n;++i){
        if(i!=n-1) cout << a[i] <<" ";
        else cout << a[i];
    }
    cout << endl;
    return sw;
}

int main() {
    int N; cin >> N; vector<int> A(N);
    for(int i=0;i<N;++i) cin >> A[i];
    int sw = BubbleSort(A, N);
    
    cout << sw << endl;
    return 0;
}
