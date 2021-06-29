#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void countingSort(vector<int> &A, vector<int> &B, int k, int n) {
    vector<int> C(k+1);
    for(int i=0;i<=k;i++) {
        C[i] = 0;
    }
    for(int j=0;j<n;j++) {
        C[A[j]]++;
    }
    for(int i=1;i<=k;i++) {
        C[i] += C[i-1];
    }
    for(int j=n-1;j>=0;j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}



int main() {
//    ifstream in("input.txt");
//    cin.rdbuf(in.rdbuf());
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;i++) {
        cin >> A[i];
    }
    
    int k = 10000;
    vector<int> B(n);
    countingSort(A, B, k, n);
    for(int i=0;i<n;i++) {
        if(i!=0) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}
