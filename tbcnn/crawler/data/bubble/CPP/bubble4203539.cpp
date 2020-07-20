#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>A, int N){
    bool flag = 1;
    int count = 0; 
    for (int i = 0; flag; i++){
        flag = 0;
        for(int j = N-1; j >=i+1; j--){
            if(A.at(j) < A.at(j-1)){
                swap(A.at(j), A.at(j-1));
                count ++;
                flag = 1;
            }
        }
    }
    for(int i = 0; i < N; i++){ 
      if (i > 0) cout << ' ';
      cout << A.at(i);
    }
  	cout << endl;
    cout << count << endl;
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);
    
    bubbleSort(A, N);
    
}
