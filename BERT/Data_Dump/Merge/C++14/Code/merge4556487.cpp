#include <bits/stdc++.h>
using namespace std;
#define M 2000000000

int cnt = 0;
vector<int> L(250005);
vector<int> R(250005);

void merge(vector<int> &vec,int n,int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;

  for(int i=0;i<n1;i++) L.at(i) = vec.at(left+i);
  for(int i=0;i<n2;i++) R.at(i) = vec.at(mid+i);
  L.at(n1) = M;
  R.at(n2) = M;
  int i = 0, j = 0;
  for(int k = left;k<right;k++){
    cnt++;
    if(L.at(i) <= R.at(j)){
      vec.at(k) = L.at(i++);
    }else{
      vec.at(k) = R.at(j++);
    }
  }
}

void mergeSort(vector<int> &vec,int n,int left,int right){
  if(left+1<right){
    int mid = (left + right) / 2;
    mergeSort(vec,n,left,mid);
    mergeSort(vec,n,mid,right);
    merge(vec,n,left,mid,right);
  }
}

int main(){
  int n,i;

  cin >> n;
  vector<int> vec(n);
  for(i=0;i<n;++i){
    cin >> vec.at(i);
  }

  mergeSort(vec,n,0,n);
  for(i=0;i<n-1;i++){
    cout << vec.at(i);
    cout << " ";
  }
  cout << vec.at(n-1) << endl;
  cout << cnt << endl;
  return 0;
}

