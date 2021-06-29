#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ns;

int main()
{
  int n; cin >> n; // number of iterations
  ns = vector<int> {istream_iterator<int>{cin}, istream_iterator<int>{}};
  int k = *max_element(ns.begin(), ns.end());
  int cts[k+1] {0};
  for(int i : ns) {
    ++(cts[i]);
  }
  bool printed=false;
  for(int i=0; i<(k+1); ++i) {
    for(int c=0; c<cts[i]; ++c) {
      if(!printed) {
        cout << i;
        printed = true;
      } else {
        cout << " " << i;
      }
    }
  }
  cout << endl;
}
