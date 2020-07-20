#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const int MAX_A = 100;

int sort(const int N, int (*a)[MAX_A]) {
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= i + 1; j--) {
            if ((*a)[j] < (*a)[j - 1]) {
                swap((*a)[j], (*a)[j - 1]);
                count++;
            }
        }
    }

    return count;
}

int main(void) {
    int N;
    cin >> N;

    int A[MAX_A];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = sort(N, &A);

    cout << A[0];
    for (int i = 1; i < N; i++) {
        cout << " " << A[i];
    }
    cout << endl;

    cout << count << endl;

    return 0;
}

