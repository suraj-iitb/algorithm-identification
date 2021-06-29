#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath> 
#include <cctype>

using namespace std;

int bsort(int A[], int N) {
    int count = 0;
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j - 1] > A[j]) {
                swap(A[j - 1], A[j]);
                flag = true;
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = bsort(A, N);

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << count << endl;
    return 0;
}
