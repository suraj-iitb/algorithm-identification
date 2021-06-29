#include <stdio.h>
#define MAX 500001
#define SENTINEL 1000000001

void merge_sort(int[], int, int);
void merge(int[], int, int, int);
int count = 0;

int main(){

    int n, S[MAX], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    merge_sort(S, 0, n);
    for (i = 0; i < n - 1; i++) {
        printf("%d ", S[i]);
    }
    printf("%d\n", S[n - 1]);
    printf("%d\n", count);

    return 0;
}

void merge_sort(int s[], int left, int right){
    if(left + 1 < right) {      // ２つかどうか判定
        int mid = (left + right) / 2;
        merge_sort(s, left, mid);
        merge_sort(s, mid, right);
        merge(s, left, mid, right);
    }
}

void merge(int s[], int left, int mid, int right){
    int i, k;
    int n1 = mid - left + 1;
    int n2 = right - mid + 1;
    int L[n1], R[n2];
    for(i = 0; i < (n1 - 1); i++){
        L[i] = s[left + i];
    }

    for(i = 0; i < (n2 - 1); i++){
        R[i] = s[mid + i];
    }

    L[n1 - 1] = SENTINEL;
    R[n2 - 1] = SENTINEL;

    i = 0;
    int j = 0;

    for(k = left; k < right; k++){
        if(L[i] <= R[j]){
            s[k] = L[i];
            i++;
        }
        else {
            s[k] = R[j];
            j++;
        }
            count++;
    }
}
