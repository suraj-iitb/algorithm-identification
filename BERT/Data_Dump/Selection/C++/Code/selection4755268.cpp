#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec.at(i);
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (vec.at(j) < vec.at(minj)) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(vec.at(i), vec.at(minj));
            count++;
        }
    }
    for (int i = 0; i < N-1; i++) {
        cout << vec.at(i) << " ";
    }
    cout << vec.at(N-1) << endl;
    cout << count << endl;
}
