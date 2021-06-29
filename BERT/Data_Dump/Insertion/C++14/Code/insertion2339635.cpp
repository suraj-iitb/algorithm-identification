#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
vector<int> A;

void write(vector<int> v) {
    for (int i = 0; i < N - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[N - 1] << endl;
}

int main() {
    cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j > 0; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
            } else {
                break;
            }
        }
        write(A);
    }
    return 0;
}
