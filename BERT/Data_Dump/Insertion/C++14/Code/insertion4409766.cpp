#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a, int N) {
    for (int i = 0; i < N; i++) {
        int v = a.at(i);
        int j = i - 1;

        while (j >= 0 && a.at(j) > v) {
            a.at(j+1) = a.at(j);
            j--;
        }

        a.at(j+1) = v;

        for(int i = 0; i < N; i++) {
            if (i == N-1) {
                cout << a.at(i) << '\n';
                break;
            }
            cout << a.at(i) << " ";
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    insertionSort(a, N);
    return 0;

}
