#include <stdio.h>
#define N 500001
#define SENTINEL 1000000005

int n, S[N];
int cnt = 0;

void merge(int left, int mid, int right){

    int n1 = mid - left;
    int n2 = right - mid;

    // 番兵用に一つ余分に確保
    int L[n1+1], R[n2+1];

    int i, j, k;

    // 配列を2つに分ける
    for(i = 0; i < n1; i++) L[i] = S[left + i];
    for(i = 0; i < n2; i++) R[i] = S[mid + i];

    // 配列の最後に番兵を設置
    L[n1] = R[n2] = SENTINEL;

    i = j =0;

    for (k = left; k < right; k++) {
        cnt++;
        if(L[i] <= R[j]) S[k] = L[i++];
        else S[k] = R[j++];
    }

    // int iw = 0, il = left, ir = mid;
    //
    // while(il < mid && mid < right){
    //     if(S[il] <= S[ir]) work[iw++] = S[il++];
    //     else  work[iw++] = S[ir++];
    // }
    //
    // while(il < mid) work[iw++] = S[il++];
    // while(ir < right) work[iw++] = S[ir++];
}

void mergeSort(int left, int right){
    int mid;

    // 配列の長さが1以下ならソート済
    if(right - left <= 1) return;

    // 配列をleft~mid, mid~rightの2つに分けてソート
    mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid, right);

    // 配列をマージ
    merge(left, mid, right);
}



int main() {

    int i;
    int left, right;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &S[i]);

    left = 0;
    right = n;

    mergeSort(left, right);

    for(i = 0; i < n-1; i++) printf("%d ", S[i]);
    printf("%d\n", S[n-1]);
    printf("%d\n", cnt);

    return 0;

}
