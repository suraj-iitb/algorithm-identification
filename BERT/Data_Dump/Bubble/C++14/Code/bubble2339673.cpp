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
vector<int> v;

int main() {
    cin >> N;
    v = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (v[i] > v[j]) {
                cnt++;
            }
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[N - 1] << endl;
    cout << cnt << endl;
}
