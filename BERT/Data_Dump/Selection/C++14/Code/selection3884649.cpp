#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define _GLIBCXX_DEBUG
static const int MAX = 100;

int selectionSort(int A[], int N){
    int sw = 0, minj;

    rep(i, N - 1){
        minj = i;

        rep2(j, i, N){
            if(A[j] < A[minj]) minj = j;
        }

        swap(A[i], A[minj]);
        if(i != minj) sw++;
    }
    return sw;
}

void trace(int A[], int N){
    int i;
    rep(i, N){
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main(){
    int A[MAX], N;

    cin >> N;
    rep(i, N) cin >> A[i];

    int sw = selectionSort(A, N);
    trace(A, N);

    cout << sw << endl;
}
