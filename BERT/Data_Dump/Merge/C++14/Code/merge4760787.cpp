#include "bits/stdc++.h"
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T>& v, bool is_reverse=false, int num=0){
  if(num == 0) num = (int)v.size();
  if(is_reverse) for(int i=num-1; i>=0; i--){ cout<<v[i]; if(i!=0) cout<<" ";}
  else for(int i=0; i<num; i++){ cout<<v[i]; if(i!=num-1) cout<<" ";}
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

const int INF = 1e9+1;
template <typename T>
void merge(vector<T> &a, int left, int mid, int right, int &num){
  int n1 = mid - left;
  int n2 = right - mid;
  vector<T> L(n1+1), R(n2+1);
  for(int i=0; i<n1; i++) L[i] = a[left+i];
  for(int i=0; i<n2; i++) R[i] = a[mid+i];
  L[n1] = INF;
  R[n2] = INF;
  int l_id = 0, r_id = 0;
  for(int i=left; i<right; i++){
    if(L[l_id] <= R[r_id]){
      a[i] = L[l_id];
      l_id++;
    }
    else{
      a[i] = R[r_id];
      r_id++;
    }
    num++;
  }

  return;
}

template <typename T>
void mergeSort(vector<T> &a, int left, int right, int &num){
  if(left + 1 < right){
    int mid = (left + right) / 2;
    mergeSort(a, left, mid, num);
    mergeSort(a, mid, right, num);
    merge(a, left, mid, right, num);
  }
  return;
}
int main(){
  //http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_B&lang=ja
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  int num = 0;
  mergeSort(a, 0, n, num);
  
  print_vec(a);
  cout << num << endl;
  return 0;
}


