#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N; //要素数の入力
  vector <int> data (N); // data：N個の要素を含む配列
  for (int i=0; i<N; i++){
  	cin >> data.at(i); // dataの要素入力
  }
  for (int j=1; j<N; j++){
   for (int i =0; i<N; i++){
      if (i==0)
        cout << data.at(i);
      else
        cout << " " << data.at(i);
    }
    cout << endl;
    int v=data.at(j);
    int k = j-1;
    while (k >=0 && data.at(k) > v) {
      data.at(k+1) = data.at(k);
      k--;
    }
    data.at(k+1)= v;
  }
  for (int i =0; i<N; i++){
      if (i==0)
        cout << data.at(i);
      else
        cout << " " << data.at(i);
    }
  cout << endl;
}

