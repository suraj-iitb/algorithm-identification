#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N;
  	cin >> N;
    vector<int> A(N);
	for(int i =0;i<N;i++){
      cin >> A.at(i);
    }
    int flag = 1;
    int count = 0;
    int k = 1;
    while(flag){
      flag =0;
      for(int i = N-1;i>=k;i--){
        if(A.at(i)<A.at(i-1)){
          swap(A.at(i-1),A.at(i));
          flag = 1;
          count++;
        }
      }
	k++;
    }
    for(int h=0;h<N-1;h++){
      cout << A.at(h) << ' ';
    }
    cout << A.at(N-1) << endl;
    cout << count <<endl;
        
}
