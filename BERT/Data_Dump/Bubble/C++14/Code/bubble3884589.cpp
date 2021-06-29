#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
static const int MAX = 100;

int bubbleSort(int A[], int N){
    int sw = 0;
    bool flag = 1;

    for(int i = 0; flag; i++){
        flag = 0;
        
        for(int j = N-1; j >= i+1; j--){
            if(A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                sw++;
            }
        }
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

    int sw = bubbleSort(A, N);
    trace(A, N);

    cout << sw << endl;
}
