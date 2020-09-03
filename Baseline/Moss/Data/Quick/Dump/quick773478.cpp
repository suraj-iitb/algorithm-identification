#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl

struct Node {
    int number;
    char kind;
    int index;
};

int partition(vector<Node>& A, const int l, const int r) {
    const int pivot = A[r - 1].number;
    int head = l;
    for(int i = l; i < r; i++) {
        if(A[i].number <= pivot) {
            swap(A[head], A[i]);
            head++;
        }
    }
    return head - 1;
}

void quicksort(vector<Node>& A, const int l, const int r) {
    if(r - l > 1) {
        int g = partition(A, l, r);
#if 0
        for(int i = 0; i <= g; i++) {
            cerr << A[i].number << ' ';
        }
        cerr << "| ";
        for(int i = g + 1; i < r; i++) {
            cerr << A[i].number << ' ';
        }
        cerr << endl;
#endif
        quicksort(A, l, g);
        quicksort(A, g + 1, r);
    }
}

int main() {
    int N; cin >> N;
    vector<Node> A;
    for(int i = 0; i < N; i++) {
        int number;
        char kind;
        cin >> kind >> number;
        A.push_back((Node){ number, kind, i });
    }
    quicksort(A, 0, N);

    bool stable = true;
    for(int i = 1; i < N; i++) {
        if(A[i - 1].number == A[i].number && A[i - 1].index > A[i].index) {
            stable = false;
        }
    }
    cout << (stable ? "Stable" : "Not stable") << endl;
    for(int i = 0; i < N; i++) {
        cout << A[i].kind << ' ' << A[i].number << endl;
    }
}
