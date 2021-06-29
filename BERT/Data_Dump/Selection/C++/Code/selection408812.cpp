
#include <iostream>
#include <algorithm>

using namespace std;

int N, v[110], count = 0;

int main(void) {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];

    for(int i = 0; i < N; i++) {
        int min = i;
        for(int j = i; j < N; j++) {
            if(v[j] < v[min]) min = j;
        }
        if(min != i) {
            swap(v[i], v[min]);
            ::count += 1;
        }
    }
    for(int i = 0; i < N; i++) {
        if(i == N - 1) {
            cout << v[i] << endl;
        } else {
            cout << v[i] << " ";
        }
    }
    cout << ::count << endl;
    return 0;
}
