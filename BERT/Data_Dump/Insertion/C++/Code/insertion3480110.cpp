#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N;
    int A[1000];

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            A[j] = v;
            j--;
            // A[j+1] = v;
        }

        //表示
        for(int l = 0; l < N; l++) {
            cout << A[l];
            if(l != N-1) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
