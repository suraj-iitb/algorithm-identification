#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename TYPE>
void print_vec(const vector<TYPE>& v, int num=0){
  if(num == 0) num = (int)v.size();
	for(int i=0; i<num; i++){
		cout << v[i]; if(i!=num-1) cout << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

template <typename T>
void SWAP(T &a, T &b){
  a = a^b;// a^b 
  b = a^b;// (a^b)^b
  a = a^b;// (a^b)^(a^b^b)
}

template <typename T>
void insertionSort(vector<T> &a, T N){
  //http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=ja
  for(int i=0; i<N-1; i++){
    int j = i;
    while(j>=0 && a[j] > a[j+1]){
      SWAP(a[j], a[j+1]);
      j--;
    }
    print_vec(a);
  }
}
template <typename T>
void bubbleSort(vector<T> &a, int n){
  //http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=ja
  ll num = 0;
  for(int i=0; i<n; i++){
    for(int j=n-1; j>i; j--){
      if(a[j-1] > a[j]){
        SWAP(a[j-1], a[j]);
        num++;
      }
    }
  }
  print_vec(a);
  cout << num << endl;
  return;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  bubbleSort(a, n);

  return 0;
}


