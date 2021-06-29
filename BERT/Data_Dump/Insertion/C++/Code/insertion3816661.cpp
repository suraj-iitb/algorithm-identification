#include <iostream>
#include <vector>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl;

int main() {
    int N;
    cin >> N;
    vector<int> A;

    for (int i = 0; i < N; i++) {
       int x;
       cin >> x;
       A.push_back(x);
    }

    // index 0 の時
    cout << A[0];
    for (int i = 1; i < N; i++) {
        cout << " " << A[i];
    }
    cout  << endl;

    for (int i = 1; i <= N - 1; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;

        // index 1 以降の時
        cout << A[0];
        for (int i = 1; i < N; i++) {
            cout << " " << A[i];
        }
        cout  << endl;
    }

}
