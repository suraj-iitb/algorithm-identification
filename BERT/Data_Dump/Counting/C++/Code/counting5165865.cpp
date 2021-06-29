#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
typedef long long ll;
#define N 2000001
#define M 10001
vector<int> A(N);
vector<int> B(N);
vector<int> C(M);
int n;

void CountingSort(){
  for(int i = 1; i <= n; i++){
    C.at(A.at(i))++;
  }
  for(int i = 1; i < M; i++){
    C.at(i) += C.at(i-1);
  }
  for(int i = n; i > 0; i--){
    B.at(C.at(A.at(i))) = A.at(i);
    C.at(A.at(i))--;
  }
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> A.at(i);
  }
  CountingSort();
  for(int i = 1; i < n; i++){
    cout << B.at(i) << " ";
  }
  cout << B.at(n) << endl;
  return 0;
}
