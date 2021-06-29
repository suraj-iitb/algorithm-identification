#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (int)n ; i++)
typedef long long ll;

int bubble_sort(vector<int> &A, int n){
  int flag = 1;
  int i = 0;
  int c = 0;
  while( flag ){
    flag = 0;
    for( int j = n-1 ; j > i ; j--){
      if( A.at(j-1) > A.at(j) ){
        swap(A.at(j-1),A.at(j));
        flag = 1;
        c++;
      }   
    }
    i++;
  }
  return c;
}

int main(){
  int n;
  cin >> n ;
  
  vector<int> A(n);
  rep(i,n){
    cin >> A.at(i);
  }

  int c = bubble_sort(A,n);

  rep(i,n){
    cout << A.at(i);
    if( i < n-1 ) cout << " " ;
  }
  cout << endl << c << endl;
}
