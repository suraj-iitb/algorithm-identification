#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
}

void print_vect(vector<int> v){
  vector<int>::iterator i = v.begin();
  cout << *i++;
  while (i != v.end())
  {
    cout << " " << *i++;
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  int N, count = 0;
  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }
  int mini;
  for(int i = 0; i < N; i++){
    mini = i;
    for(int j = i; j < N; j++){
      if(v[j] < v[mini])
        mini = j;
    }
    if(i!=mini){
      swap(v[i], v[mini]);
      count++;
    }
  }
  print_vect(v);
  cout << count << endl;
  return 0;
}
