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

int bubble_sort(vector<int>& as) {
    int ret = 0;
    for (int i = 0; i < as.size() - 1; i++) {
        for (int j = 0; j < as.size() - 1 - i; j++) {
            if (as[j] > as[j + 1]) {
                swap(as[j], as[j + 1]);
                ret++;
            }
        }
    }
    return ret;
}

void print_all(vector<int>& as) {
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

    int swap_count = bubble_sort(as);
    print_all(as);
    cout << swap_count << endl;
}
