#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(void) {
    int N;
    cin >> N;
    int A[N];
    rep(i,N) cin >> A[i];

    for(int i=1; i<N; i++){
      cout << A[0];
      for(int k=1; k<N; k++){
        cout << " " << A[k];
      }
      cout << endl;
      int v;
      v = A[i];
      int j = i-1;
      while(j>=0 && A[j]>v){
        A[j+1] = A[j];
        j--;
      }
      A[j+1] = v;
    }

    
    cout << A[0];
    for(int k=1; k<N; k++){
      cout << " " << A[k];
    }
    cout << endl;


    return 0;
}

