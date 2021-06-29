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

int selection_sort(vector<int>& as) {
    int ret = 0;
    for (int i = 0; i < as.size(); i++) {
        int min_idx = i;
        for (int j = i; j < as.size(); j++) {
            if (as[j] < as[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(as[min_idx], as[i]);
            ret++;
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

    int swap_count = selection_sort(as);
    print_all(as);
    cout << swap_count << endl;
}
