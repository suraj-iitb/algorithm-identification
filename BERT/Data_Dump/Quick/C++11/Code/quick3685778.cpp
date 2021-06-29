#include <iostream>
#include <cstdio>

struct Card {
    int number;
    char simbol;
};

Card C[100000];
Card L[100000/2 + 3];
Card R[100000/2 + 3];

void Merge(Card *C, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) {
        L[i] = C[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = C[mid + i];
    }

    L[n1].number = 1000000001;
    R[n2].number = 1000000001;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].number <= R[j].number) {
            C[k] = L[i];
            i++;
        } else {
            C[k] = R[j];
            j++;
        }
    }
}

void MergeSort(Card *C, int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2 ;
        MergeSort(C, left, mid);
        MergeSort(C, mid, right);
        Merge(C, left, mid, right);
    }
}

int Partition(Card *C, int p, int r)
{
    int x = C[r].number;
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (C[j].number <= x) {
            i += 1;
            // swap
            Card val_i = C[i];
            C[i] = C[j];
            C[j] = val_i;
        }
    }
    i += 1;
    // swap
    Card val_i = C[i];
    C[i] = C[r];
    C[r] = val_i;
    return i;
}

void QuickSort(Card *C, int p, int r)
{
    if (p < r) {
        int q = Partition(C, p, r);
        QuickSort(C, p, q-1);
        QuickSort(C, q+1, r);
    }
}

int main(int argc, char *argv[])
{
    int n;
    char S[10];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", S);
        scanf("%d", &C[i].number);
        C[i].simbol = S[0];
    }

    Card C_cmp[n];
    for (int i = 0; i < n; i++) {
        C_cmp[i] = C[i];
    }

    QuickSort(C, 0, n-1);
    MergeSort(C_cmp, 0, n);

    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (C[i].simbol != C_cmp[i].simbol) {
            stable = false;
        }
    }

    if (stable) std::cout << "Stable" << std::endl;
    else std::cout << "Not stable" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << C[i].simbol << " " << C[i].number << std::endl;
    }
}
