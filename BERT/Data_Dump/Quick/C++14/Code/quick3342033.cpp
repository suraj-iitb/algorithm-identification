#include <iostream>
#include <algorithm>
#include <vector>

struct Card {
    char suit;
    int value;
};

void exchange(std::vector<Card>& A, int i, int j) {
    Card temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Partition(std::vector<Card>& A, int p, int r) {
    int x = A[r].value;
    int i = p-1;
    for (int j=p; j<r; ++j) {
        if (A[j].value <= x) {
            i++;
            exchange(A, i, j);
        }
    }
    exchange(A, i+1, r);
    return i+1;
}

void QuickSort(std::vector<Card>& A, int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

void Merge(std::vector<Card>& A, int left, int mid, int right) {
    std::vector<Card> L, R;
    for (int i=0; i<(mid-left); ++i) L.push_back(A[left+i]);
    for (int i=0; i<(right-mid); ++i) R.push_back(A[mid+i]);
    L.push_back(Card{'X', 1000000000});
    R.push_back(Card{'X', 1000000000});
    
    int i=0;
    int j=0;
    int k=left;
    
    while (k < right) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
}

void MergeSort(std::vector<Card>& A, int left, int right) {
    if (left+1 < right) {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}

int main() {
    int N, tempi;
    char tempc;
    std::cin >> N;
    
    std::vector<Card> A, B;
    for (int i=0; i<N; ++i) {
        std::cin >> tempc >> tempi;
        A.push_back(Card{tempc, tempi});
        B.push_back(Card{tempc, tempi});
    }
    
    QuickSort(A, 0, N-1);
    MergeSort(B, 0, N);
    
    bool ans = true;
    for (int i=0; i<N; ++i) {
        if (A[i].suit != B[i].suit) {
            ans = false;
            break;
        }
    }
    
    std::cout << (ans ? "Stable" : "Not stable") << std::endl;
    for (auto &&e : A) {
        std::cout << e.suit << " " << e.value << std::endl;
    }
}
