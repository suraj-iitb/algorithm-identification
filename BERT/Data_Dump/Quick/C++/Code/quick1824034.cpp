#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class T{
  public:
    ll value;
    char c;

    bool operator == (const T &t)const{
      return value == t.value && c == t.c;
    }
};

bool isStable(vector<T> input, vector<T> sorted){
  set<int> nums;
  for(int i = 0; i < input.size(); i++){
    nums.insert(input[i].value);
  }
  for(set<int>::iterator it = nums.begin(); it != nums.end(); it++){
    list<char> order;
    for(int i=0; i < input.size(); i++){
      if(input[i].value == (*it)){
        order.push_back(input[i].c);
      }
    }
    list<char>::iterator c = order.begin();
    for(int i = 0; i < sorted.size(); i++){
      if(sorted[i].value == (*it)){
        if(sorted[i].c != *c) return false;
        else c++;
      }
    }
  }
  return true;
}

ll partition(vector<T> &A, ll p, ll r){
  ll x = A[r].value;
  ll i = p-1;
  for(ll j = p; j < r; j++){
    if(A[j].value <= x){
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

void quicksort(vector<T> &A, ll p, ll r){
  if(p < r){
    ll q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<T> v(n);
  for(ll i = 0; i < n; i++){
    cin >> v[i].c >> v[i].value;
  }
  vector<T> org(v);
  quicksort(v, 0, n-1);
  if(isStable(org, v)){
    cout << "Stable" << endl;
  }else{
    cout << "Not stable" << endl;
  }
  for(ll i = 0; i < n; i++){
    cout << v[i].c << " " << v[i].value << endl;
  }
  return 0;
}
