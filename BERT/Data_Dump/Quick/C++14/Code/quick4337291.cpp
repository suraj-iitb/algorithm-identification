#include <bits/stdc++.h>
using namespace std;

struct Card {
    char pic;
    int num;
};

void merge(vector<Card> &C1, int left, int mid, int right) {
    int n1, n2;
    n1 = mid - left;
    n2 = right - mid;
    vector<Card> L(n1 + 1);
    vector<Card> R(n2 + 1);
    for (int i = 0; i < n1; i++) {
        L.at(i) = C1.at(left + i);
    }
    L.at(n1).pic = 'Z';
    L.at(n1).num = 1000000001;
    for (int i = 0; i < n2; i++) {
        R.at(i) = C1.at(mid + i);
    }
    R.at(n2).pic = 'Z';
    R.at(n2).num = 1000000001;

    int i, j;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++) {
        if (L.at(i).num <= R.at(j).num) {
            C1.at(k) = L.at(i);
            i++;
        } else {
            C1.at(k) = R.at(j);
            j++;
        }
    }
}

void mergeSort(vector<Card> &C1, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(C1, left, mid);
        mergeSort(C1, mid, right);
        merge(C1, left, mid, right);
    }
}

bool isStable(vector<Card> &C1, vector<Card> &C2) {
    for (int i = 0; i < C1.size(); i++) {
        if (C1.at(i).pic != C2.at(i).pic) {
            return false;
        }
    }

    return true;
}

int partition(vector<Card> &C2, int p, int r) {
    Card t, x;
    x = C2.at(r);
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (C2.at(j).num <= x.num) {
            t = C2.at(++i);
            C2.at(i) = C2.at(j);
            C2.at(j) = t;
        }
    }
    t = C2.at(++i);
    C2.at(i) = C2.at(r);
    C2.at(r) = t;

    return i;
}

void quickSort(vector<Card> &C2, int p, int r) {
    if (p < r) {
        int q = partition(C2, p, r);
        quickSort(C2, p, q - 1);
        quickSort(C2, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<Card> C1(n);
    vector<Card> C2(n);
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c;
        scanf("%d", &x);
        C1.at(i).pic = C2.at(i).pic = c;
        C1.at(i).num = C2.at(i).num = x;
    }

    mergeSort(C1, 0, n);
    quickSort(C2, 0, n - 1);

    if (isStable(C1, C2)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", C2.at(i).pic, C2.at(i).num);
    }
}
