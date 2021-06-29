#include <iostream>
using namespace std;

#define MAX 100000
#define SENTINEL 2000000000

struct Card { int number; char mark;};

int partition(Card C[], int p, int r) {
    int x = C[r].number;
    int i = p - 1;
    Card tmp;
    for (int j = p; j < r; j++) {
        if (C[j].number <= x) {
            i++;
            tmp = C[i];
            C[i] = C[j];
            C[j] = tmp;
        }
    }
    tmp = C[i+1];
    C[i+1] = C[r];
    C[r] = tmp;
    return i + 1;
}

void q_sort(Card C[], int p, int r) {
    if (p < r) {
        int q = partition(C, p, r);
        q_sort(C, p, q-1);
        q_sort(C, q+1, r);
    }
}

Card L[MAX/2+2], R[MAX/2+2];
void merge(Card C[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) {
        L[i] = C[left+i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = C[mid+i];
    }
    L[n1].number = R[n2].number = SENTINEL;
    int li = 0, ri = 0;
    for (int i = left; i < right; i++) {
        if (L[li].number <= R[ri].number) {
            C[i] = L[li++];
        } else {
            C[i] = R[ri++];
        }
    }
}

void merge_sort(Card C[], int left, int right) {
    if (left+1 < right) {
        int mid = (left + right) / 2;
        merge_sort(C, left, mid);
        merge_sort(C, mid, right);
        merge(C, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    Card C1[MAX], C2[MAX];
    int number;
    char mark;
    for (int i = 0; i < n; i++) {
        cin >> mark >> number;
        C1[i].mark = mark; C1[i].number = number;
        C2[i] = C1[i];
    }
    q_sort(C1, 0, n-1);
    merge_sort(C2, 0, n);
    bool is_stable = true;
    for (int i = 0; i < n; i++) {
        if (C1[i].number != C2[i].number || C1[i].mark != C2[i].mark) is_stable = false;
    }
    if (is_stable) {
        cout << "Stable";
    } else {
        cout << "Not stable";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << C1[i].mark << " " << C1[i].number << endl;
    }
    return 0;
}

