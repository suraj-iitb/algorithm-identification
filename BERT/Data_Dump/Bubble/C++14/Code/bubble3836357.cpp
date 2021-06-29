#include<bits/stdc++.h>
using namespace std;

int Bubble(vector<int> a, int N) {
    int j=0;
    int cnt=0;
    while(j<N*N) {
        for(int i=N-1; i>=1; i--) {
            if(a.at(i-1)>a.at(i)) {
                int tmp;
                tmp = a.at(i);
                a.at(i) = a.at(i-1);
                a.at(i-1) = tmp;
                cnt++;
            }
        }
        j++;
    }
  	for(int i=0; i<N; i++) {
        cout<<a.at(i);
        i==N-1 ? cout<<endl: cout<<' ';
    }
  
    return cnt;
}

int main() {
    int N;  cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin>>a.at(i);
    int count = Bubble(a, N);
    cout << count << endl;
}
