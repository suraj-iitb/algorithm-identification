#include<bits/stdc++.h>
using namespace std;

int Selection(vector<int> a,int N) {
  	int cnt=0;
  	bool flag=false;
    for(int i=0; i<N; i++) {
        int minj = i;
        for(int j=i; j<N; j++) {
            if(a.at(j)<a.at(minj)) {
              minj = j;
              flag=true;
            }
        }
      	if(flag==true) {
          swap(a.at(i), a.at(minj));
          cnt++;
          flag=false;
        }
    }

    for(int i=0; i<N; i++) {
        cout << a.at(i);
        i==N-1? cout<<endl: cout<<' ';
    }
  
  	return cnt;
}

int main() {
    int N;  cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin>>a.at(i);
    cout << Selection(a, N) << endl;
}
