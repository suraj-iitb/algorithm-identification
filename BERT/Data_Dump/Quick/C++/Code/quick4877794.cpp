#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define SENTINEL 2000000000

struct Card{
    char suit;
    int value;
};
struct Card L[MAX/2+1], R[MAX/2+2];
void merge(struct Card a[], int left, int mid, int right){
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for(i=0; i<n1; i++)
        L[i] = a[left+i];
    for(i=0; i<n2; i++)
        R[i] = a[mid+i];
    L[n1].value = R[n2].value = SENTINEL;
    i = j = 0;
    for(k=left; k<right; k++){
        if(L[i].value <= R[j].value)
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
}
void mergeSort(struct Card a[], int left, int right){
    if(left+1 < right){
        int mid = (left+right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}
int partition(struct Card a[], int p, int r){
    struct Card x = a[r];
    int i = p - 1;
    for(int j=p; j<r; j++){
        if(a[j].value <= x.value){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[r], a[i+1]);
    return i+1;
}
void quickSort(struct Card a[], int p, int r){
    if(p < r){
        int q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }

}

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    char s[5];
    struct Card A[MAX], B[MAX];
    bool isStable = true;
    for(int i=0; i<n; i++){
        scanf("%s %d", s, &A[i].value);
        B[i].suit = A[i].suit = s[0];
        B[i].value = A[i].value;
    }
    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);

    
    int i = 0;
    for(i=0; i<n; i++)
        if(A[i].suit != B[i].suit)
            isStable = false;
    if(isStable)
        printf("Stable\n");
    else
        printf("Not stable\n");
    for(i=0; i<n; i++)
        printf("%c %d\n", B[i].suit, B[i].value);
    

    return 0;
}   
