#include<bits/stdc++.h>
using namespace std;

int Insertion(vector<int> a, int N) {
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j>=1; j--) {
            if(a.at(j-1)>a.at(j)) {
                int tmp;
                tmp = a.at(j);
                a.at(j) = a.at(j-1);
                a.at(j-1) = tmp;
            }
        }
        for(int i=0; i<N; i++) {
            cout<<a.at(i);
            i==N-1 ? cout<<endl: cout<<' ';
        }
    }
}

int main() {
    int N;  cin >> N;
    vector<int> a(N);
    for(int i=0; i<N; i++) cin>>a.at(i);
  	for(int i=0; i<N; i++) {cout<<a.at(i);i==N-1? cout<<endl: cout<<' ';}
    Insertion(a, N);
}
