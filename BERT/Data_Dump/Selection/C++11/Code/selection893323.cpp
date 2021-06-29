#include <algorithm>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cstring>
#include <tuple>
#include <bitset>
#include <unordered_map>
using namespace std;
typedef long long ll;

void print(vector<int> vi) {
    for (int i=0; i<(int)vi.size(); ++i) {
        cout << (i == 0 ? "" : " ") << vi[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; ++i) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i=0; i<N; ++i) {
        int mini = i;
        for (int j=i; j<N; ++j) {
            if (A[mini] > A[j]) {
                mini = j;
            }
        }
        if (mini != i) {
            swap(A[mini], A[i]);
            ++ ans;
        }
    }
    print(A);
    cout << ans << endl;

    return 0;
}
