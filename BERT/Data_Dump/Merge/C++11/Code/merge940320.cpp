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

int merge(vector<int>& as, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> ls(n1 + 1), rs(n2 + 1);
    for (int i = 0; i < n1; i++) {
        ls[i] = as[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rs[i] = as[mid + i];
    }
    ls[n1] = rs[n2] = INT_MAX;
    for (int i = 0, j = 0, k = left; k < right; k++) {
        if (ls[i] <= rs[j]) {
            as[k] = ls[i++];
        } else {
            as[k] = rs[j++];
        }
    }
    return right - left;
}

int merge_sort(vector<int>& as, int left, int right) {
    if (left + 1 >= right) {
        return 0;
    }
    int mid = (left + right) / 2;
    int ret = 0;
    ret += merge_sort(as, left, mid);
    ret += merge_sort(as, mid, right);
    ret += merge(as, left, mid, right);
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> as(n);
    for (auto& a : as) {
        cin >> a;
    }
    int comparison = merge_sort(as, 0, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << as[i];
    }
    cout << endl;
    cout << comparison << endl;
}
