#include <stdio.h>
#include <math.h>
int N = 0;
void merge(int*, int, int, int);
void mergeSort(int*, int, int);


int main() {
    int i, quantity;
    int num[500001];
    scanf("%d", &quantity);
    for(i = 0; i < quantity; i++){
        scanf("%d\n", &num[i]);
    }
    mergeSort(num, 0, quantity);
    for(i = 0; i < quantity - 1; i++){
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    printf("%d\n", N);

    return 0;
}

void merge(int *num, int left, int mid, int right){
    int i, j, k, n1, n2; 
    int L[500000];
    int R[500000];
    n1 = mid - left;
    n2 = right - mid;
    for(i = 0; i < n1; i++){
        L[i] = num[left + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = num[mid + i];
    }
    L[n1] = INFINITY;
    R[n2] = INFINITY;
    i = 0;
    j = 0;
    for(k = left; k < right; k++){
        if(L[i] <= R[j]){
            num[k] = L[i];
            i++;
            N++;
        }
        else{
            num[k] = R[j];
            j++;
            N++;
        }
    }
}

void mergeSort(int *num, int left, int right){
    int mid;
    if(left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(num, left, mid);
        mergeSort(num, mid, right);
        merge(num, left, mid, right);
    }
}
