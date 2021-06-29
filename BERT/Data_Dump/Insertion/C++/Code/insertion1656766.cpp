#include <iostream>
#include <vector>
using namespace std;

int main(){
    long N;
    cin >> N;
    vector<long> A(N);
    for (long i = 0; i < N; i++){
        cin >> A[i];
    }
    for (long i = 0; i < N; i++){
        long v, j;
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v){
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for (long k = 0; k < N - 1; k++){
            cout << A[k] << " ";
        }
        cout << A[N - 1] << endl;
    }
    return 0;
}
