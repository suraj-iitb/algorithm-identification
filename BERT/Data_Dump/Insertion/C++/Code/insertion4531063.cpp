#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef long long ll;



void Insertion_Sort(vector<int> &A,int N){
  int i,j,temp;
  //整列されていない配列の先頭から始める
  for(int i = 1 ; i < N ; i++){
    rep(k,N){
      cout << A.at(k);
      if(k < N-1) cout << " " ;
    }
    cout << endl;
    j = i;
    while( (j > 0) && (A.at(j-1) > A.at(j)) ){
      //隣り合う要素を比較して、後ろから前に適切な位置まで繰り返し交換する
      temp = A.at(j-1);
      A.at(j-1) = A.at(j);
      A.at(j) = temp;
      j--;
      
    }
    
  }
}


int main(){
  int n;
  cin >> n ;

  vector<int> A(n);
  rep(i,n){
    cin >> A.at(i);
  }

  Insertion_Sort(A,n);

  rep(i,n){
    cout << A.at(i);
    if(i < n-1) cout << " " ;
  }
  cout << endl;
}
