#include <stdio.h>
#define MAX 100000
#define INF 100000000

struct Node {
    char pattern;
    int value;
};

struct Node L[MAX], R[MAX];

void merge(struct Node num[], int n, int left, int mid, int right){
    int i, j, k, n1, n2; 
    n1 = mid - left;
    n2 = right - mid;
    for(i = 0; i < n1; i++){
        L[i] = num[left + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = num[mid + i];
    }

    L[n1].value = INF;
    R[n2].value = INF;
    i = 0;
    j = 0;
    for(k = left; k < right; k++){
        if(L[i].value <= R[j].value){
            num[k] = L[i];
            i++;
        }
        else{
            num[k] = R[j];
            j++;
        }
    }
}

void mergeSort(struct Node num[], int n, int left, int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(num, n, left, mid);
        mergeSort(num, n, mid, right);
        merge(num, n, left, mid, right);
    }
}

int partition(struct Node A[], int n, int p, int r){
    int i, j;
    struct Node a, b;
    a = A[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if(A[j].value <= a.value){
            i++;
            b = A[i];
            A[i] = A[j];
            A[j] = b;
        }
    }

    b = A[i + 1]; 
    A[i + 1] = A[r]; 
    A[r] = b;

    return i + 1;
}

void quickSort(struct Node A[], int n, int p, int r){
    int q;
    if(p < r){
        q = partition(A,n,p,r);
        quickSort(A, n, p, q-1);
        quickSort(A, n, q + 1, r);
    }
}

int main(){
    int n, i, v;
    struct Node A[MAX], B[MAX];
    char X[10];
    int check = 1;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%s%d", X, &v);
        A[i].pattern = B[i].pattern = X[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n-1);

    for(i = 0; i < n; i++){
        if(A[i].pattern != B[i].pattern) check = 0;
    }

    if(check == 1) printf("Stable\n");
    else printf("Not stable\n");
    for(i = 0; i < n; i++){
        printf("%c %d\n", B[i].pattern, B[i].value);
    }

    return 0;
}
