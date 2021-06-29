#include<stdio.h>

using namespace std;

int s[500000];

int cnt;

void merge(int s[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int* L = new int[n1+1];
    int* R = new int[n2+1];
    for(int i = 0; i < n1; i++){
        L[i] = s[left+i];
    }
    for(int i = 0; i < n2; i++){
        R[i] = s[mid+i];
    }
    L[n1] = 1000000001;
    R[n2] = 1000000001;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            s[k] = L[i];
            i++;
        }
        else{
            s[k] = R[j];
            j++;
        }
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int s[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(s, left, mid);
        mergeSort(s, mid, right);
        merge(s, left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }

    mergeSort(s, 0, n);

    for(int i = 0; i < n; i++){
        if(i){
            printf(" %d", s[i]);
        }
        else{
            printf("%d", s[i]);
        }
    }
    printf("\n");
    printf("%d\n", cnt);
}
