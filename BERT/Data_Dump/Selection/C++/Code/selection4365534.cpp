#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
  	cin >> N;
    vector<int> A(N);
	for(int i =0;i<N;i++){
      cin >> A.at(i);
    }
    int count = 0;
    for(int k=0;k<N-1;k++){
      int minj = k;
      for(int j=k+1;j<N;j++){
        if(A.at(j)<A.at(minj)){
          minj = j;
        }
      }
      if(A.at(minj) != A.at(k)){
        swap(A.at(minj),A.at(k));
        count++;
      }
     }
    
    for(int h=0;h<N-1;h++){
      cout << A.at(h) << ' ';
    }
    cout << A.at(N-1) << endl;
    cout << count <<endl;
        
}
