#include <iostream>
#define NMAX 100000
#define SENTINEL 1000000001
using namespace std;

int partition(int array[], char array2[], int p, int r) {
    int x = array[r];
    int i = p - 1;
    for (int j = p; j < r; j++){
        if (array[j] <= x) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            char tem = array2[i];
            array2[i] = array2[j];
            array2[j] = tem;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[r];
    array[r] = temp;
    char tem = array2[i + 1];
    array2[i + 1] = array2[r];
    array2[r] = tem;
    return i + 1;
}

void merge(int A[],char B[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int L[NMAX],R[NMAX];
    char LL[NMAX],RR[NMAX];

    for(int i=0;i<=n1-1;i++){
        L[i]=A[left+i];
        LL[i]=B[left+i];
    }
    for(int i=0;i<=n2-1;i++){
        R[i]=A[mid+i];
        RR[i]=B[mid+i];
    }
    L[n1]=SENTINEL;
    R[n2]=SENTINEL;
    int i=0,j=0;
    for(int k=left;k<=right-1;k++){
        if(L[i]<=R[j]){
            A[k]=L[i];
            B[k]=LL[i];
            i++;
        }
        else{
            A[k]=R[j];
            B[k]=RR[j];
            j++;
        }
    }
}

void merge_sort(int A[],char B[],int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        merge_sort(A,B,left,mid);
        merge_sort(A,B,mid,right);
        merge(A,B,left,mid,right);
    }
}


void quicksort(int array[], char arr2[], int p, int r) {
    if (p < r) {
        int q = partition(array, arr2,  p, r);
        quicksort(array, arr2, p, q-1);
        quicksort(array, arr2, q + 1, r);
    }
}

int main() {
    int pickles, i;
    int stable = 0;
    cin >> i;
    int array[i] = {};
    char array2[i] = {};
    char array3[i] = {};
    int array4[i] = {};

    for (int j = 0; j < i; j++) {
        cin >> array2[j] >> array[j];
    }

    for (int p = 0; p < i; p++) {
        array3[p] = array2[p];
        array4[p] = array[p];
    }
    merge_sort(array4, array3,0,i);

    quicksort(array, array2, 0, i - 1);
    for (int j = 0; j < i; j++) {
        if ((array2[j] != array3[j])) stable = 1;
        }
    if (stable == 0) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    for (int j = 0; j < i; j++) {
        cout << array2[j] << " " << array[j] << endl;
    }

}
