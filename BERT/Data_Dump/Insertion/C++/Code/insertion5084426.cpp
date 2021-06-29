#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    for (int i=0; i<N; i++) {
        cin >> A[i];
        if (i==N-1) cout << A[i] << endl;
        else cout << A[i] << ' ';
        
    }
        
    
    // Insertion Sort
    for (int i=1; i<N; i++) {
        int v = A[i];
        int j = i-1;
        
        while (j>=0 && A[j]>v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k=0; k<N-1; k++) cout << A[k] << ' ';
        cout << A[N-1] << endl;
    }
    
    
}
