#include <iostream>
#include <vector>
using namespace std;

void change(int &a, int &b){
  int tmp = a;
  a = b;
  b = tmp;
}

int main(){
  ios::sync_with_stdio(false);
  int N, count = 0;
  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }
  for(int i = 0; i < N; i++)
    for(int j = N-1; j >= i+1; j--)
      if(v[j]<v[j-1]){
        change(v[j],v[j-1]);
        count++;
      }
  vector<int>::iterator i = v.begin();
  cout << *i++;
  while (i != v.end())
  {
    cout << " " << *i++;
  }
  cout << endl;
  cout << count << endl;
  return 0;
}
