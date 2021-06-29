#include<bits/stdc++.h>
using namespace std;

void insertion(vector<int> a, int N) {
    for(int i = 1; i < N; i++) {

        int tmp = a.at(i);
        int j = i - 1;

        while(j >= 0 && a.at(j) > tmp) {
            a.at(j+1) = a.at(j);
            a.at(j) = tmp;
          	if(j >= 1) j--;
        }      
        if(a.at(j) <= a.at(j+1)) {
              for(int k = 0; k < N; k++) {
                  cout << a.at(k);
                  if(k != N-1) cout << ' ';
              }
              cout << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i< N; i++) {
        cin >> a.at(i);
    }
  
  	for(int i = 0; i < N; i++) {
		cout << a.at(i);
      	if(i != N-1) cout << ' ';
    }
  	cout << endl;
  
    insertion(a, N);
}
