#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int N, vector<int> &A){

  for(int k = 0; k < N; k++){
    cout << A.at(k);
    if(k == N-1){
      cout << endl;
    }
    else{
      cout << " ";
    }
  }

  for (int i = 1; i < N; i++){
    int v = A.at(i);
    int j = i - 1;
    while ((j >= 0) && (A.at(j) > v)){
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = v;

    for(int k = 0; k < N; k++){
      cout << A.at(k);
      if(k == N-1){
        cout << endl;
      }
      else{
        cout << " ";
      }
    }
  }
}

int main(){
  int N; //要素数
  cin >> N;

  vector<int> A(N);//数列要素

  //数列に入力
  for(int &a: A){
    cin >> a;
  }

  insertion_sort(N, A);

}

