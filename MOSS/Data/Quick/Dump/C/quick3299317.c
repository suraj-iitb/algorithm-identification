#include <stdio.h>
#define EXTREME 1000000000
#define MAX_ELEM 500000


typedef struct card{
    char mark;
    int x;
} Card;

Card L[MAX_ELEM / 2];
Card R[MAX_ELEM / 2];

Card c1[1000000];
Card c2[1000000];

void merge(Card A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;

    for(int i = 0; i < n1; i++) L[i] = A[left+i];
    for(int i = 0; i < n2; i++) R[i] = A[mid+i];
    L[n1].x = EXTREME;
    R[n2].x = EXTREME;

    /* compare with L and R */
    int i = 0, j = 0;
    for(int k = left; k < right; k++){
        if(L[i].x <= R[j].x){
            A[k] = L[i];
            i++;
        } else{
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(Card A[], int left, int right){
    if(right - left > 1){
        int mid = (right+left)/2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);

    }
}


int partition(Card A[], int p, int r){
    int i = p - 1;
    Card last = A[r];
    Card tmp;
    for(int j = p; j < r; j++){
        if(A[j].x <= last.x){
            i += 1;
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }

    tmp = A[i + 1];
    A[i + 1]= A[r];
    A[r] = tmp;

    return i + 1;
}

int quicksort(Card A[], int p, int r){
    if(p < r){
        int q = partition(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }

    return 0;
}

int main(){
    int i, n, v;

    /* 安定ならば0、不安定なら1を表す変数 */
    int judge = 0;
    char S[10];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s %d", S, &v);
        c1[i].mark = c2[i].mark = S[0];
        c1[i].x = c2[i].x = v;
    }


    quicksort(c1, 0, n - 1);
    merge_sort(c2, 0, n);

    for(i = 0; i < n; i++){
        if(c1[i].mark != c2[i].mark){
            judge = 1;
        } 
    }

    if(judge == 1){
        printf("Not stable\n");
    } else{
        printf("Stable\n");
    }

    for(i = 0; i < n; i++){
        printf("%c %d\n", c1[i].mark, c1[i].x);
    }
    return 0;
}
