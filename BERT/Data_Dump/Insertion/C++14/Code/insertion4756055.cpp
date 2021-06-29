#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, int num=0){
  if(num == 0) num = (int)v.size();
  for(int i=0; i<num; i++){ cout << v[i]; if(i!=num-1) cout << " ";}
  cout << endl;
}

template <typename T>
void print_pairvec(const vector<T> &v, int num=0){
  if(num == 0) num = (int)v.size();
  for(int i=0; i<num; i++){ cout << v[i].first << v[i].second; if(i!=num-1) cout << " ";}
  cout << endl;
}

template <typename T>
void print_vec2(const vector<vector<T>>& v){
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
  print_vec(a);
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

template <typename T>
void selectionSort(vector<T> &a, int n){
  ll num = 0;
  for(int i=0; i<n; i++){
    int min_id = i;
    for(int j=i+1; j<n; j++){
      if(a[min_id] > a[j]) min_id = j;
    }
    if(min_id != i){
      num++;
      SWAP(a[i], a[min_id]);
    }
  }
  print_vec(a);
  cout << num << endl;
  return;
}

using cP = pair<char, int>;
void BubbleSort(vector<cP> &a, int n){
  for(int i=0; i<n; i++){
    for(int j=n-1; j>i; j--){
      if(a[j-1].second > a[j].second) swap(a[j-1], a[j]);
    }
  }
}

void SelectionSort(vector<cP> &a, int n){
  for(int i=0; i<n; i++){
    int min_id = i;
    for(int j=i+1; j<n; j++){
      if(a[i] > a[j]) min_id = j;
    }
    if(min_id != i) swap(a[i], a[min_id]);
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  insertionSort(a, n);
  // bubbleSort(a, n);
  // selectionSort(a, n);

  // vector<cP> a(n), b, c;
  // for(int i=0; i<n; i++) cin >> a[i].first >> a[i].second;
  // b = a;
  // c = a;
  // BubbleSort(b, n);
  // SelectionSort(c, n);

  // print_vec(b);
  // cout << "Stable" << endl;//BubbleSortは常に安定
  // print_vec(c);
  // if(b==c) cout << "Stable" << endl;
  // else cout << "Not stable" << endl;
  return 0;
}


