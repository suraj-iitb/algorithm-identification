#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void print_all(const vector<int>& as) {
    for (int i = 0; i < as.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << as[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (auto& a : as) {
        cin >> a;
    }
    print_all(as);

    for (int i = 1; i < as.size(); i++) {
        int key = as[i];
        int j = i - 1;
        while (j >= 0 && as[j] > key) {
            as[j + 1] = as[j];
            j--;
        }
        as[j + 1] = key;

        print_all(as);
    }
}
