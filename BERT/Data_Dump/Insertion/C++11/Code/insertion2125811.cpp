#include<iostream>
#include<vector>
using namespace std;

void print(const vector<int64_t> &a){
  size_t n = a.size();
  for(int i=0;i<n-1;i++){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
}

void insertionSort(vector<int64_t> &a){
  size_t n = a.size();
  for(int i=1;i<n;i++){
    int v = a[i];
    int j = i - 1;
    while(j>=0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1]=v;
    print(a);
  }
}

int main(){
  int N;
  vector<int64_t> v;

  cin >> N;
  v.resize(N);
  for(int i=0;i<N;i++){
    cin >> v[i];
  }

  print(v);
  insertionSort(v);

  return 0;
}
