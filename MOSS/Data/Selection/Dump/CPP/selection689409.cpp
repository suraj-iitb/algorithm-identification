#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int mini = i;
        for(int j = i + 1; j < N; j++) {
            if(vec[j] < vec[mini]) mini = j;
        }
        if(mini != i) {
            ans++;
            swap(vec[i], vec[mini]);
        }
    }
    for(int i = 0; i < N; i++) {
        cout << vec[i] << "\n "[i < N - 1];
    }
    cout << ans << endl;
}
