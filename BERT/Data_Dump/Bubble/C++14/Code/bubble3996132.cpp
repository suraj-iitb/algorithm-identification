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

void bubbleSort(int A[], int N){
    bool flag = 1;
    // 5 3 2 4 1
    while(flag){
        flag = 0;
        for (int j = N-1; j >=1; j--){
            if(A[j] < A[j-1]){
                int x = A[j];
                A[j] = A[j - 1];
                A[j - 1] = x;
                ans++;
                flag = 1;
            }
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
    bubbleSort(A, N);
    cout << ans << endl;
    return 0;
}

