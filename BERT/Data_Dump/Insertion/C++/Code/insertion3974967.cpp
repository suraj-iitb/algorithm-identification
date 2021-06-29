#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

void trace(int A[], int N){
    for (int i = 0; i < N; i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionSort(int A[], int N){
    int j, i, v;
    for(i = 1; i < N; i++) {
        v = A[i]; // 2
        j = i - 1; // 0
        while (j >= 0 && A[j]> v){ // 0 >= 0 && 5 > 2 
            A[j + 1] = A[j]; //index 1 = 5
            j--; // -1
        }
        A[j + 1] = v; // index 0 = 2
        trace(A, N);
    }
}

int main() {
    // ifstream in("data1.txt");
    // cin.rdbuf(in.rdbuf());
    int N;
    cin >> N;
    int A[N];
    rep(i, N) cin >> A[i];
    trace(A, N);
    insertionSort(A, N);
    return 0;
}

