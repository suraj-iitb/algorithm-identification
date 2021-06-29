// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=jp
// Insertion Sort

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
  int n;cin>>n;
  vector<int> num(n);

  for(int i=0;i<n;++i)
    cin>>num.at(i);
 
  // Insertion Sort
  for(int i=1;i<=n;++i){
    for(int k=0;k<n;++k){
      cout << num.at(k);
      if(k!=n-1)cout << " ";
    }
    cout << endl;

    if(i==n) break;
    int key = num.at(i);
    int j = i-1;

    while(j>=0 and num.at(j) > key){
      num.at(j+1) = num.at(j);
      j--;
      num.at(j+1) = key;
    }

  }

   return EXIT_SUCCESS;
}
