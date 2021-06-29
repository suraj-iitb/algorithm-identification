#include<stdio.h>
#define INFITY 1000000001
#define SIZE 100000

typedef struct {
    char pat;
    int val;
}card;

void merge(card* A, int left, int mid, int right) {
    int n1, n2;
    int i, j, k;
    card L[SIZE], R[SIZE];

    n1 = mid - left;
    n2 = right - mid;

    for (i = 0; i < n1; i++) L[i] = A[left + i];
    
    for (i = 0; i < n2; i++) R[i] = A[mid + i];
    
    L[n1].val = INFITY;
    R[n2].val = INFITY;
    i = 0;
    j = 0;

    for (k = left; k < right; k++) {
        if (L[i].val <= R[j].val) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(card* A, int left, int right) {
    int mid;

    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(card* A, int p, int r) {
    int x;
    int i, j;
    card temp;
    x = A[r].val;
    i = p - 1;
    for (j = p; j < r; j++) {
        if (A[j].val <= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
   
    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return i + 1;
}

void quickSort(card* A, int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}


int main() {
    card mer[SIZE], qui[SIZE];
    int n, val;
    int i,flag=1;
    char pat;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c%d", &pat, &val);
        mer[i].pat = qui[i].pat = pat;
        mer[i].val = qui[i].val = val;
    }

    mergeSort(mer, 0, n);
    quickSort(qui, 0, n - 1);

    for (i = 0; i < n; i++) {
        if (qui[i].val == mer[i].val && mer[i].pat != qui[i].pat) {
            flag = 0;
            break;
        }
    }

    if (flag == 0) printf("Not stable\n");
    else printf("Stable\n");
    for (i = 0; i < n; i++) {
        printf("%c %d\n", qui[i].pat, qui[i].val);
    }

    return 0;
}

