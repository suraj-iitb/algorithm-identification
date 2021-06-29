#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int A[N];
    int i, j, k, v;
    for(i=0; i<N; i++)
        cin >> A[i];

    cout << A[0];
    for(k=1; k<N; k++)
        cout << ' ' << A[k];
    cout << endl;

    for(i=1; i<N; i++) {
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        cout << A[0];
        for(k=1; k<N; k++)
            cout << ' ' << A[k];
        cout << endl;
    }

    return 0;
}
