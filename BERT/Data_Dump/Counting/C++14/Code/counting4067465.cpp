#include <iostream>
#include <string>
using namespace std;
const int MAX = 10000;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int A[n], B[n], C[MAX];
    for (int i = 0; i < MAX; i++) C[i] = 0;
    for (int i = 0; i < n; i++){
        cin >> A[i];
        C[A[i]]++;
    }
    for (int i = 1; i < MAX; i++) C[i] = C[i] + C[i-1];
    for (int i = n-1; i >= 0; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    for (int i = 1; i < n; i++) cout << B[i] << " ";
    cout << B[n] << "\n";
    return 0;
}

