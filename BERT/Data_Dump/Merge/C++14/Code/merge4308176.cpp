#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& num) {
    int n = num.size();
    for (int i = 0; i < n; ++i) {
        cout << num[i];
        if (i != n - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void insertion_sort(vector<int>& a) {
    int n = a.size();

    for (int i = 1; i < n; ++i) {
        // この状態では，[0, i - 1]はソートされている．
        int x = a[i];
        int j = i - 1;
        // a[i]より大きいものがあれば，ずらしていく．
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = x;
    }
}

void bubble_sort(vector<int>& a) {
    int n = a.size();
    bool flag = true;
    while (flag) {
        flag = false;
        // 配列の後ろから，隣接する要素を交換していく．
        for (int i = n - 1; i >= 0; --i) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                flag = true;
            }
        }
    }
}

void selection_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        // a[i]からa[n - 1]までの最小値をa[i]と交換する．
        int mini = i;
        for (int j = i; j < n; ++j) {
            if (a[j] < a[mini]) { mini = j; }
        }
        swap(a[i], a[mini]);
    }
}

int merge(vector<int>& a, int left, int mid, int right) {
    // [left, mid)と[mid, right)までは，それぞれソート済み．
    int n1 = mid - left, n2 = right - mid;

    vector<int> l(n1 + 1), r(n2 + 1);
    for (int i = 0; i < n1; ++i) { l[i] = a[i + left]; }
    for (int i = 0; i < n2; ++i) { r[i] = a[i + mid]; }

    l[n1] = INT_MAX;
    r[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        // l[i]とr[j]のうち小さい方をa[k]に代入する．
        if (l[i] <= r[j]) {
            a[k] = l[i++];
        } else {
            a[k] = r[j++];
        }
    }
    return right - left;
}

int merge_sort(vector<int>& a, int left, int right) {
    int sum = 0;
    // [left, right)をソートする．
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        // 分割して，それぞれソートする．
        sum += merge_sort(a, left, mid);
        sum += merge_sort(a, mid, right);
        // 部分問題の解を統合する．
        sum += merge(a, left, mid, right);
    }
    return sum;
}

int partition(vector<int>& a, int left, int right) {
    // [left, right)をa[right - 1]を基準に分割する．
    int center = a[right - 1];
    int i = left;
    for (int j = left; j < right - 1; ++j) {
        if (a[j] <= center) {
            swap(a[i], a[j]);
            ++i;
        }
    }
    swap(a[i], a[right - 1]);
    return i;
}

void quick_sort(vector<int>& a, int left, int right) {
    if (left < right) {
        int center = partition(a, left, right);
        quick_sort(a, left, center);
        quick_sort(a, center + 1, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) { cin >> a[i]; }

    vector<int> b = a;
    int sum = merge_sort(b, 0, n);
    quick_sort(a, 0, n);
    print(a);
    cout << sum << endl;

    return 0;
}
