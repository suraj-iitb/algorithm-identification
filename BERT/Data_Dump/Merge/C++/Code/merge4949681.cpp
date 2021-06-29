#include <iostream>
static const int MAX = 500005;
static const int INFTY = 2000000000;
using namespace std;

class Ary {
    private:
        int A[MAX];
        int L[MAX/2], R[MAX/2];
        int n; // 要素数
        int cnt; // 交換回数
        void merge(int left, int mid, int right);
        void mSort(int left, int right);
        void showCount() {cout << cnt << endl;}
    public: 
        Ary(int a); // コンストラクタ 
        void mergeSort();
        void show();
};
// Ary class member
Ary::Ary(int a) {
    cnt = 0;
    n = a;
    for (int i = 0; i < n; i++) cin >> A[i];
}
void Ary::merge(int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) A[k] = L[i++];
        else A[k] = R[j++];
    }
}
void Ary::mSort(int left, int right) {
    int mid = (left + right) / 2;
    if (left + 1 < right) {
        mSort(left, mid);
    mSort(mid, right);
    merge(left, mid, right);
    }
}
void Ary::mergeSort() {
    mSort(0, n);
}
void Ary::show() {
    for (int i = 0; i < n; i++) {
        if (i) cout << " " << A[i];
        else cout << A[i];
    }
    cout << endl;
    showCount();
}

int main() {
    int n;
    cin >> n;
    Ary ary(n);
    ary.mergeSort();
    ary.show();
    return 0;
}



