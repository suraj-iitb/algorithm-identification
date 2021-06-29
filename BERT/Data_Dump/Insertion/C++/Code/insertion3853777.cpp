#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &v, int N) {
    for (int i = 1; i <= (N - 1); ++i) {
        int k = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > k) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = k;
        for (int k = 0; k < (N - 1); ++k){
                cout << v[k] << " ";
        }
        cout << v[N-1] << endl;
    }
}

int main() {
    int N; cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (N - 1); ++i) {
        cout << a[i] << " ";
    }
    cout << a[N-1] << endl;
    insert(a, N);
    return 0;
}
