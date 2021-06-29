#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int n;
  	cin >> n;
    vector<int> A(n);
	for(int i =0;i<n;i++){
      cin >> A.at(i);
    }
    int v = 0;
    for(int k=0;k<n;k++){
      v=A.at(k);
      int j = k-1;
      while(j>=0 && A.at(j) > v){
        A.at(j+1) = A.at(j);
        j--;
      }
      A.at(j+1)=v;
      for(int x = 0;x<n-1;x++){
        cout << A.at(x) << ' ';
      }
      cout << A.at(n-1)<< endl;
    }
        
}
