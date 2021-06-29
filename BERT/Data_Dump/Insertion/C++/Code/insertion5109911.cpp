#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 20000;
int a[maxn];

void trace(int *A, int N){
    int i;
    for(i = 0; i < N; i++){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int *A, int N){
    int i, j, flag;
    for(i = 1; i < N; i++){
        flag = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > flag){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = flag;
        trace(A, N);
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    trace(a, N);
    insertionSort(a, N);
    return 0;
}

