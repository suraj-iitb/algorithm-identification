#include <iostream>
#include <vector>

using namespace std;

int cnt;

void Merge(vector<int> &A){
  int n = (int)A.size();
  
  if(n > 1){
    vector<int> L(A.begin(), A.begin()+n/2);
    vector<int> R(A.begin()+n/2, A.end());

    Merge(L);
    Merge(R);

    int l = (int)L.size(), r = (int)R.size();
    for(int i = 0,j = 0,k = 0 ; i < n ; i++){
      cnt++;
      if(k == r) A[i] = L[j++];
      else if(j == l) A[i] = R[k++]; 
      else if(L[j] < R[k]) A[i] = L[j++];
      else A[i] = R[k++];
    }
  }
  
}

int main(){
  int n;
  
  cin >> n;
  vector<int> v(n);
  for(int i = 0 ; i < n ; i++){
    cin >> v[i];
  }

  Merge(v);

  int len = (int)v.size();
  for(int i = 0 ; i < len ; i++){
    if(i == len-1) cout << v[i] << endl;
    else cout << v[i] << " ";
  }
  cout << cnt << endl;

  return 0;
}
