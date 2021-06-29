#include<cstdio>

#define MAX 100000
#define SENTINEL 2000000000

struct Card {//構造体Cardを定義する。
    char mark;
    int number;
};

struct Card L[MAX/2 + 2], R[MAX/2 + 2];

int i;

void merge(struct Card A[], int n, int left, int mid, int right){//マージの動作。
    i = 0;
    int j = 0, k = left;
    int n1 = mid - left;
    int n2 = right - mid;
    while (i < n1){
        L[i] = A[left + i];
        i += 1;
    }
    i = 0;
    while (i < n2){
        R[i] = A[mid + i];
        i += 1;
    }
    L[n1].number = R[n2].number = SENTINEL;//番兵を置く。
    i = j = 0;
    while(k < right){
        if(L[i].number <= R[j].number){
            A[k] = L[i];
            i += 1;
        } else {
            A[k] = R[j];
            j += 1;
        }
        k += 1;
    }
}

void mergesort(struct Card A[], int n, int left, int right){//出力が安定であるかどうかを調べるためにマージソートを利用する。
    int mid;
    if (left + 1 < right){
        mid = (left + right)/2;
        mergesort(A, n, left, mid);
        mergesort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int partition(struct Card A[], int n, int p, int r){//パーティションの動作。これをクイックソートの動作で利用する。
    struct Card a, b, x;
    x = A[r];
    int d = p - 1;
    int j = p;
    while(j <= r - 1){
        if(A[j].number <= x.number){
            d += 1;
            a = A[d];
            b = A[j];
            A[d] = b;
            A[j] = a;
        }
        j += 1;
    }
    a = A[d + 1];
    b = A[r];
    A[d + 1] = b;
    A[r] = a;
    return d + 1;
}

void quicksort(struct Card A[], int n, int p, int r){//クイックソートの動作。
    int q;
    if(p < r){
        q = partition(A, n, p, r);
        quicksort(A, n, p, q - 1);
        quicksort(A, n, q + 1, r);
    }
}

int main(){
    int n, v;
    char S[5];
    struct Card M[MAX], Q[MAX];
    int stable = 1;
    scanf("%d", &n);
    i = 0;
    while(i < n){
        scanf("%s %d", S, &v);
        M[i].mark = Q[i].mark = S[0];
        M[i].number = Q[i].number = v;
        i += 1;
    }
    
    mergesort(M, n, 0, n);
    quicksort(Q, n, 0, n - 1);
    
    i = 0;
    while(i < n){//このwhile文で安定な出力を行っているかどうか調べる。
        if(M[i].mark != Q[i].mark){
            stable = 0;
            break;
        }
        i += 1;
    }
    if (stable == 1){
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    i = 0;
    while(i < n){
        printf("%c %d\n", Q[i].mark, Q[i].number);
        i += 1;
    }
    return 0;
}
