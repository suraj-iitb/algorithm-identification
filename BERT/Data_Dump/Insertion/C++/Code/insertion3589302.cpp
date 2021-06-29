#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
        for ( int k = 0; k < v.size(); k++ ) {
            cout << (k==0 ? "" : " ") << v[k];
        }
        cout << '\n';
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for ( int i = 0; i < N; i++ ) {
        cin >> A[i];
    }
    print(A);
    int v,j;
    for ( int i = 1; i < N; i++ ) {
        v = A[i];
        j = i - 1;
        while ( j >= 0 && A[j] > v ) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(A);
    }
    return 0;
}
