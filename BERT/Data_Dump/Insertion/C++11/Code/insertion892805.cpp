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
using namespace std;
typedef long long ll;
void print(vector<int> vec) {
    for (int i=0; i<(int)vec.size(); ++i) {
        cout << (i == 0 ? "" : " ") << vec[i];
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }

    print(A);
    for (int j=1; j<n; ++j) {
        int key = A[j];
        int i = j-1;
        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            -- i;
        }
        A[i+1] = key;
        print(A);
    }

    return 0;
}
