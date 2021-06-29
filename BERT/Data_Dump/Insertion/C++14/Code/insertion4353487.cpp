#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  for(int i = 0; i < N; i++){
    int v = A.at(i);
    int j = i - 1;
    while(j >= 0 && A.at(j) > v){
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = v;
    for(int i = 0; i < N; i++){
      cout << A.at(i);
      if(i != N-1) cout << " ";
    }
    cout << endl;
  }
  return 0;
}
