#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int A[1000];
int ans = 0;

void trace(int A[], int N){
    for (int i = 0; i < N; i++){
        if(i>0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

void selectionSort(int A[], int N){
    for (int i = 0; i < N; i++){
        int minj = i;
        for (int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[i] != A[minj]){
            ans++;
            swap(A[i], A[minj]);
        }
    }
    trace(A, N);
}

int main() {
    // ifstream in("data1.txt");
    // cin.rdbuf(in.rdbuf());
    int N;
    cin >> N;
    rep(i, N) cin >> A[i];
    selectionSort(A, N);
    cout << ans << endl;
}

