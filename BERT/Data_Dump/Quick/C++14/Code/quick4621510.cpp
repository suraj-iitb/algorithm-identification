#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

struct Card {
    char sute;
    int rank;
public:
    bool operator == (const Card& rhs) const
    {
        return ((sute == rhs.sute) && (rank == rhs.rank));
    }
};

Card in[100000];
Card out[100000];


int partition(Card a[], int left, int right) {
    int x = a[right].rank;
    int i = left - 1;
    for (int j = left; j <= right - 1; ++j) {
        if (a[j].rank <= x) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}


void quicksort(Card a[], int left, int right) {
    if (left < right) {
        int mid = partition(a, left, right);
        quicksort(a, left, mid - 1);   // pivotを境に再帰的にクイックソート
        quicksort(a, mid + 1, right);
    }
}

bool isStable(Card in[], Card out[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            for (int a = 0; a < size - 1; ++a) {
                for (int b = a + 1; b < size; ++b) {
                    if ((in[i].rank == in[j].rank) 
                        && (in[i].sute == out[b].sute) && (in[i].rank == out[b].rank) 
                        && (in[j].sute == out[a].sute) && (in[j].rank == out[a].rank)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void bubbleSort(Card a[], int size) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = size - 1; j >= 1; --j) {
            if (a[j].rank < a[j - 1].rank) {
                swap(a[j], a[j - 1]);
                flag = true;
            }
        }
    }
}

void merge(Card A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    // L[0...n1], R[0...n2] を生成
    Card *L = new Card[n1+1];
    Card *R = new Card[n2+1];
    for (int i = 0; i < n1; ++i) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = A[mid + i];

    }
    L[n1].rank = INT_MAX;
    R[n2].rank = INT_MAX;

    int i = 0;
    int j = 0;
    for (int k = left; k < right; ++k) {
        if (L[i].rank <= R[j].rank) {
            A[k] = L[i];
            ++i;
        }
        else {
            A[k] = R[j];
            ++j;
        }
    }
    delete[] L;
    delete[] R;
}

void mergeSort(Card A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}


bool equals(Card in[], Card out[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if ((in[i].sute != out[i].sute) || (in[i].rank != out[i].rank)) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> in[i].sute >> in[i].rank;
        out[i] = in[i];
    }

    quicksort(out, 0, n - 1);
#if 0
    if (n > 10000) {
        cout << "Not stable" << endl;
    }
    else {
        if (isStable(in, out, n)) {
            cout << "Stable" << endl;
        }
        else {
            cout << "Not stable" << endl;
        }
    }
#else
    mergeSort(in, 0, n - 1);
    bubbleSort(in, n);
    if (equals(in, out, n)) {
        cout << "Stable" << endl;
    }
    else {
        cout << "Not stable" << endl;
    }
#endif
    for (int i = 0; i < n; ++i) {
        cout << out[i].sute << " " << out[i].rank << endl;
    }

}


