#include <iostream>
#include <algorithm>
using namespace std;
#include <cmath>

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int k = 0; k < N-1; k++) cout << A[k] << " ";
    cout << A[N-1] << endl;

    int v, j;
    for (int i = 1; i < N; i++){
        v = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k = 0; k < N-1; k++) cout << A[k] << " ";
        cout << A[N-1] << endl;
    }



    return 0;
}
