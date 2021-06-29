#include <cstdio>
using namespace std;
#define MAX 100000
#define INF 200000000

struct Card {
    char suit;
    int value; 
};

void merge(struct Card C[], int left, int mid, int right);
void mergeSort(struct Card C[], int left, int right);
int partition(struct Card C[], int p, int r);
void quicksort(struct Card C[], int p, int r);

struct Card L[MAX/2 + 2], R[MAX / 2 + 2];

int main() {
    int n;
    scanf("%d", &n);
    struct Card A[MAX], B[MAX];
    char m[10];
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%s %d", m, &num);
        A[i].suit = B[i].suit = m[0];
        A[i].value = B[i].value = num;
    }

    mergeSort(A, 0, n);
    quicksort(B, 0, n-1);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if ( A[i].suit != B[i].suit) {
            flag = false;
            break;
        }
    }
    if (flag) printf("Stable\n");
    else printf("Not stable\n");
    for (int i = 0; i < n; i++)
        printf("%c %d\n", B[i].suit, B[i].value);
}


int partition(struct Card C[], int p, int r) {
    int i = p - 1;
    struct Card temp;
    for (int j = p; j < r; j++) {
        if (C[j].value <= C[r].value) {
            i++;
            temp = C[i]; C[i] = C[j]; C[j] = temp;
        }
    }
    temp = C[i+1]; C[i+1] = C[r]; C[r] = temp;
    return i + 1;
}

void quicksort(struct Card C[], int p, int r) {
    if (p < r) {
        int q = partition(C, p, r);
        quicksort(C, p, q - 1);
        quicksort(C, q + 1, r);
    }
}

void merge(struct Card C[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++) {
        L[i] = C[i + left];
    }
    for(int i = 0; i < n2; i++) {
        R[i] = C[i + mid];
    }
    L[n1].value = INF; R[n2].value = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            C[k] = L[i];
            i++;
        }
        else {
            C[k] = R[j];
            j++;
        }
    }
}

void mergeSort(struct Card C[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(C, left, mid);
        mergeSort(C, mid, right);
        merge(C, left, mid, right);
    }
}

